#include "window.h"

window::window(){
    framebufferResized = false;

    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    m_window = glfwCreateWindow(800, 600, "Vulkan Window", nullptr, nullptr);

    glfwSetWindowUserPointer(m_window, this);
	glfwSetFramebufferSizeCallback(m_window, framebufferResizeCallback);

}
window::~window(){
    cleanup();
}

GLFWwindow* window::get(){ return m_window; }

void window::cleanup(){ 
    glfwDestroyWindow(m_window);
    glfwTerminate();
}



void window::framebufferResizeCallback(GLFWwindow* glwindow, int width, int height){
    auto app = reinterpret_cast<window*>(glfwGetWindowUserPointer(glwindow));
	app->framebufferResized = true;
}