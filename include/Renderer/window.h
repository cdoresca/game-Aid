#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace  renderer{

class window{

    GLFWwindow* m_window;
    
    public:
    window(const char* name = "Vulkan");
    ~window();
    
    bool framebufferResized;

    GLFWwindow* get();
    void cleanup();

    static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
};

}