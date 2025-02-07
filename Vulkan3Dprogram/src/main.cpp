   #include <vulkan/vulkan.h>
   #include <GLFW/glfw3.h>
   #include <iostream>

   int main() {
       // Инициализация GLFW
       if (!glfwInit()) {
           std::cerr << "Failed to initialize GLFW" << std::endl;
           return -1;
       }

       // Установка версии OpenGL
       glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

       // Создание окна
       GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan Cube", nullptr, nullptr);
       if (!window) {
           std::cerr << "Failed to create GLFW window" << std::endl;
           glfwTerminate();
           return -1;
       }

       // Инициализация Vulkan
       VkInstance instance;
       VkApplicationInfo appInfo{};
       appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
       appInfo.pApplicationName = "Vulkan Cube";
       appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
       appInfo.pEngineName = "No Engine";
       appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
       appInfo.apiVersion = VK_API_VERSION_1_0;

       VkInstanceCreateInfo createInfo{};
       createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
       createInfo.pApplicationInfo = &appInfo;

       if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
           std::cerr << "Failed to create Vulkan instance" << std::endl;
           return -1;
       }

       // Главный цикл приложения
       while (!glfwWindowShouldClose(window)) {
           glfwPollEvents();
       }

       // Очистка ресурсов
       vkDestroyInstance(instance, nullptr);
       glfwDestroyWindow(window);
       glfwTerminate();

       return 0;
   }
   
