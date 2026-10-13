#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class window{

    GLFWwindow* m_window;
    
    public:
    window();
    ~window();
    
    bool framebufferResized;

    GLFWwindow* get();
    void cleanup();

    static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
};

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);