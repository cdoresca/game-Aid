#pragma once
#include "window.h"
#include "vkContext.h"

class platform{
    
    window* m_window;
    VkContext ctx;

    void init();
    void cleanup();

    public:
        platform();
        ~platform();

        GLFWwindow* getGLFW();
        VkContext getContext();
};