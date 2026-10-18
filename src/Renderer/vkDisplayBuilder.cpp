#include "vkDisplayBuilder.h"
#include "queueFamily.h"
#include "vkFunction.h"
#include "vkUtils.h"
#include <set>

namespace renderer{

    vkDisplayBuilder::vkDisplayBuilder(VkContext ctx,GLFWwindow* win) : ctx(ctx),window_(win){
        swapChainSupport = querySwapChainSupport(ctx.physicalDevice,ctx.surface);
        surfaceFormat = chooseSwapSurfaceFormat(swapChainSupport.formats);
        presentMode = chooseSwapPresentMode(swapChainSupport.presentsModes);
        extent = chooseSwapExtent(swapChainSupport.capabilities,window_);
    }

    VkDisplay vkDisplayBuilder::get(){ return display;}

    void vkDisplayBuilder::build(){ 
        createSwapChain();
        createImage();
        createView();
    }

    void vkDisplayBuilder::reset(){ display = {};}

    void vkDisplayBuilder::createSwapChain(){
        uint32_t imageCount = swapChainSupport.capabilities.minImageCount + 1;
        if (swapChainSupport.capabilities.maxImageCount > 0 && imageCount > swapChainSupport.capabilities.maxImageCount) {
            imageCount = swapChainSupport.capabilities.maxImageCount;
        }

        QueueFamiliesIndices indices = findQueueFamilies(ctx.physicalDevice, ctx.surface);

        std::set<uint32_t> family{ indices.presentFamily.value(), indices.graphicFamily.value(), indices.computeFamily.value(), indices.transfertFamily.value()};
        std::vector<uint32_t> list(family.begin(), family.end());

        VkSwapchainCreateInfoKHR createInfo = vkFct::getVkSwapchainCreateInfoKHR(ctx.surface, imageCount, surfaceFormat.format, surfaceFormat.colorSpace, extent, 1, VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT, family.size()>1 ? VK_SHARING_MODE_CONCURRENT:VK_SHARING_MODE_EXCLUSIVE, family.size(),list.data(),swapChainSupport.capabilities.currentTransform, VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR, presentMode, VK_TRUE,VK_NULL_HANDLE);

        VK_CHECK(vkCreateSwapchainKHR(ctx.device, &createInfo, nullptr, &display.swapChain));
    }
    
    void vkDisplayBuilder::createImage(){
        display.image = vkFct::getVkGetSwapchainImagesKHR(ctx.device, display.swapChain);
    }

    void vkDisplayBuilder::createView(){
        display.view.resize(display.image.size());
        for(std::size_t i = 0; i < display.view.size(); i++){
            VkImageViewCreateInfo info = vkFct::getVkImageViewCreateInfo(display.image[i], VK_IMAGE_VIEW_TYPE_2D, surfaceFormat.format, { VK_COMPONENT_SWIZZLE_IDENTITY,VK_COMPONENT_SWIZZLE_IDENTITY,VK_COMPONENT_SWIZZLE_IDENTITY,VK_COMPONENT_SWIZZLE_IDENTITY}, {VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1} );
            VK_CHECK(vkCreateImageView(ctx.device, &info, nullptr, &display.view[i]));
        }

    }

}