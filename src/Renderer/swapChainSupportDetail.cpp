#include "swapChainSupportDetail.h"
#include "vkQuery.h"
#include <algorithm>
#include<limits>

namespace renderer{

	
	SwapChainSupportDetails querySwapChainSupport(VkContext ctx) {
		SwapChainSupportDetails details;
		details.capabilities = vkQuery::queryVkSurfaceCapabilitiesKHR(ctx.physicalDevice, ctx.surface);
		details.formats = vkQuery::queryVkSurfaceFormatKHR(ctx.physicalDevice, ctx.surface);
		details.presentsModes = vkQuery::queryVkPresentModeKHR(ctx.physicalDevice, ctx.surface); 
		return details;
	}
	
	
	bool SwapChainSupportDetails::verifySwapSurfaceFormat(VkSurfaceFormatKHR format) {
		
		for (const auto& availableFormat : formats) {
			
			if (availableFormat.format == format.format &&
				availableFormat.colorSpace == format.colorSpace) {
				return true;
			}
		}
		return false;
	}
		
	bool SwapChainSupportDetails::verifySwapPresentMode(VkPresentModeKHR presentMode) {
		for (const auto& availablePresentMode : presentsModes) {
			if (availablePresentMode == presentMode)
			return true;
		}
		return false;
	}
		
	VkExtent2D SwapChainSupportDetails::chooseSwapExtent(GLFWwindow* window) {
		
		if (capabilities.currentExtent.width != std::numeric_limits<uint32_t>::max()) {
			return capabilities.currentExtent;
		}
		else {
			int width, height;
			glfwGetFramebufferSize(window, &width, &height);
			
			VkExtent2D actualExtent = { static_cast<uint32_t>(height), static_cast<uint32_t>(width) };
			
			actualExtent.width = std::clamp(actualExtent.width, capabilities.minImageExtent.width, capabilities.maxImageExtent.width);
			actualExtent.height = std::clamp(actualExtent.height, capabilities.minImageExtent.height, capabilities.maxImageExtent.height);
			
			return actualExtent;
		}
		
	}
}