#pragma once
#include "../IBuilder.h"
#include <vkDisplay.h>
#include "swapChainSupportDetail.h"
#include <GLFW/glfw3.h>

namespace renderer{

class vkDisplayBuilder:public IBuilder<VkDisplay>{
    public:

        vkDisplayBuilder(VkContext ctx,GLFWwindow* window);
        void reset() override;
        void build() override;

        VkDisplay get() override;
    private:
        VkDisplay display;
        VkContext ctx;

        GLFWwindow* window_;

        SwapChainSupportDetails swapChainSupport;
        VkSurfaceFormatKHR surfaceFormat;
        VkPresentModeKHR presentMode;
        VkExtent2D extent;

        void createSwapChain();
        void createImage();
        void createView();
        void createFrameBuffer();
};
}
