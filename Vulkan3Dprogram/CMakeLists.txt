cmake_minimum_required(VERSION 3.10)
project(Vulkan3Dprogram)

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(Vulkan3Dprogram src/main.cpp)

target_include_directories(Vulkan3Dprogram PRIVATE ${Vulkan_INCLUDE_DIRS})
target_link_libraries(Vulkan3Dprogram PRIVATE ${Vulkan_LIBRARIES} glfw)

