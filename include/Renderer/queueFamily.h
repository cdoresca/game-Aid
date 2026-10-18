#pragma once

#include <vulkan/vulkan.h>
#include <optional>
#include <vector>

/**
 * @brief 
 * Le struct QueueFamiliesIndices garde les indices des queues
 */
struct QueueFamiliesIndices {
	std::optional<uint32_t> graphicFamily;
	std::optional<uint32_t> presentFamily;
	std::optional<uint32_t> computeFamily;
	std::optional<uint32_t> transfertFamily;

	bool isComplete();
};

QueueFamiliesIndices findQueueFamilies(VkPhysicalDevice, VkSurfaceKHR);