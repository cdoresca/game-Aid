#include "queueFamily.h"
#include "vkQuery.h"

namespace renderer{
	bool QueueFamiliesIndices::isComplete(){
		return graphicFamily.has_value() && presentFamily.has_value() && computeFamily.has_value() && transfertFamily.has_value();
	}
	
	std::vector<QueueFamiliesIndices> findQueueFamilies(VkContext ctx) {
		std::vector<QueueFamiliesIndices> indices;
		
		std::vector<VkQueueFamilyProperties> queueFamilies = vkQuery::queryVkPhysicalDeviceQueueFamilyProperties(ctx.physicalDevice);
		
		int i = 0;
		for (const auto& queueFamily : queueFamilies) {
			QueueFamiliesIndices indice;
			VkBool32 presentSupport = false;
			vkGetPhysicalDeviceSurfaceSupportKHR(ctx.physicalDevice, i, ctx.surface, &presentSupport);

			if (presentSupport)
				indice.presentFamily = i;
			if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)
				indice.graphicFamily = i;
			if (queueFamily.queueFlags & VK_QUEUE_COMPUTE_BIT)
				indice.computeFamily = i;
			if (queueFamily.queueFlags & VK_QUEUE_TRANSFER_BIT)
				indice.transfertFamily = i;
			indice.count = queueFamily.queueCount;
			i++;
			indices.push_back(indice);
		}
	
		return indices;
	}

}