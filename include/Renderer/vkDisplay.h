#pragma once
#include <vkContext.h>
#include <vector>

namespace renderer{

struct VkDisplay
{
    VkSwapchainKHR swapChain;
    std::vector<VkImage> image;
    std::vector<VkImageView> view;
};


void destroyVkDisplay(VkContext ctx,VkDisplay display);
}