#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <cstring>
#include <iostream>

using namespace std;

// bool check(char &arr) {							//проверка на ключи
//	if (strlen(&arr) == 3) {
//		cout << "3";
//	}
//	else if(strlen(&arr) == 4){
//		cout << "4";
//	}
//	else {
//		cout << "\nНЕВЕРНО";
//	}
//	return 1;
// }

bool dividir(char &str, char &str2) {  // делим строку на отдельные слова

  char *st1 = &str;
  char *st2 = &str2;  // строка, в которую будем копировать

  int count = 0;
  char *token = strtok(st1, " ");

  while (token != NULL) {
    printf(" % s\n", token);
    token = strtok(NULL, " ");
    if (count > 4) {
      cout << "No surch file or directory";
      break;
      return 0;
    }
    count++;
  }

  char **n_str = new char *[count + 1];

  char *token2 = strtok(st2, " ");

  int i = 0;
  while (token2 != NULL) {
    *(n_str + i) = new char[strlen(token2) + 1];
    strcpy(*(n_str + i), token2);
    token2 = strtok(NULL, " ");
    i++;
  }

  for (i = 0; i < count + 1; i++) {
    std::cout << *(n_str + 1) << std::endl;
  }
  return 0;
}

bool pr_real(char &arr) {  // проверка - стоит ли grep на первом месте
  if (strncmp(&arr, "grep", 4) == 0) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  char *st = new char[80 + 1];  // создали массив символов
  fgets(st, 80 + 1, stdin);  // заполнили массив символов
  fflush(stdin);             // очистили поток от мусора

  if (strstr(st, "grep ")) {  // проверка на присутсвие слова grep
    cout << " ";
  } else {
    printf("%s: command  not found.", st);
    return 0;
  }

  int sizes = strlen(st) + 1;
  char *sin_space_st = new char[sizes];  // создали массив без пробелов

  int j = 0;  // счетчик
  for (int i = 0; i < sizes; i++) {
    if (st[i] != ' ') {
      sin_space_st[j] = st[i];
      j++;
    }
  }

  if (pr_real(*sin_space_st)) {  // проверка на присутсвие слова grep на первом
                                 // месте
    cout << " ";
  } else {
    printf("%s: command  not found.", st);
  }

  dividir(*st, *st);
}