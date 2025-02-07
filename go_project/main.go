package main

import (
	"crypto/rand"
	"encoding/base64"
	"fmt"
	"sync"
	"time"
)

type AccessKey struct {
	Key       string
	ExpiresAt time.Time
}

type AccessKeyManager struct {
	ttl  time.Duration
	keys map[string]AccessKey
	mu   sync.RWMutex
}

func NewAccessKeyManager(ttl time.Duration) *AccessKeyManager {
	return &AccessKeyManager{
		ttl:  ttl,
		keys: make(map[string]AccessKey),
	}
}

func (m *AccessKeyManager) GenerateKey(userId string) string {
	m.mu.Lock()
	defer m.mu.Unlock()

	key := generateRandomKey()
	m.keys[userId] = AccessKey{
		Key:       key,
		ExpiresAt: time.Now().Add(m.ttl),
	}
	return key
}

func (m *AccessKeyManager) ValidateKey(userId string, key string) bool {
	m.mu.RLock()
	defer m.mu.RUnlock()

	if accessKey, exists := m.keys[userId]; exists {
		if accessKey.Key == key && time.Now().Before(accessKey.ExpiresAt) {
			return true
		}
	}
	return false
}

func (m *AccessKeyManager) RevokeKey(userId string) {
	m.mu.Lock()
	defer m.mu.Unlock()

	delete(m.keys, userId)
}

func generateRandomKey() string {
	b := make([]byte, 32)
	if _, err := rand.Read(b); err != nil {
		panic(err)
	}
	return base64.StdEncoding.EncodeToString(b)
}

func main() {
	manager := NewAccessKeyManager(5 * time.Second)

	key := manager.GenerateKey("user123")
	fmt.Println("Generated Key:", key)

	isValid := manager.ValidateKey("user123", key)
	fmt.Println("Is Valid:", isValid) // isValid = true

	time.Sleep(6 * time.Second)

	isExpired := manager.ValidateKey("user123", key)
	fmt.Println("Is Expired:", isExpired) // isExpired = false

	manager.RevokeKey("user123")
	isRevoked := manager.ValidateKey("user123", key)
	fmt.Println("Is Revoked:", isRevoked) // isRevoked = false
}
