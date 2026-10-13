#include "buffer.h"

void createBuffer(const VkContext& context, const VkDeviceSize size, const VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, Buffer& buffer){

	VkBufferCreateInfo bufferInfo{};
	bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
	bufferInfo.size = size;
	bufferInfo.usage = usage;
	bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

	VK_CHECK(vkCreateBuffer(context.device, &bufferInfo, nullptr, &buffer.buffer));
		
	VkMemoryRequirements memRequirements;
	vkGetBufferMemoryRequirements(context.device, buffer.buffer, &memRequirements);

	VkMemoryAllocateFlagsInfo allocFlags{};
	allocFlags.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO;
	allocFlags.flags = VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT;

	VkMemoryAllocateInfo allocInfo{};
	allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
	allocInfo.allocationSize = memRequirements.size;
	allocInfo.memoryTypeIndex = findMemoryType(context, memRequirements.memoryTypeBits, properties);
	allocInfo.pNext = &allocFlags;

	VK_CHECK(vkAllocateMemory(context.device, &allocInfo, nullptr, &buffer.memory));
	VK_CHECK(vkBindBufferMemory(context.device, buffer.buffer, buffer.memory, 0));
}

Buffer createBuffer(const VkContext& context,const VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties){
    Buffer tmp;
	tmp.size = size;

	createBuffer(context, size, usage,  properties, tmp);
	return tmp;
}

VkDeviceAddress queryBufferAddress(VkContext& context, VkBuffer other){
    
	VkBufferDeviceAddressInfo info{};
	info.sType = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO;
	info.buffer = other;

	return vkGetBufferDeviceAddress(context.device, &info);

}


void destroyBuffer(VkContext ctx, Buffer buffer){
	vkDestroyBuffer(ctx.device,buffer.buffer,nullptr);
	vkFreeMemory(ctx.device, buffer.memory, nullptr);
}