#include "vkContext.h"
#include "vkDebug.h"
#include "asserts.h"

namespace renderer{
	void destroyVkContext(VkContext ctx){
		vkDestroyDevice(ctx.device,nullptr);
		vkDestroySurfaceKHR(ctx.instance,ctx.surface,nullptr);
		if(enableValidationLayers)
			DestroyDebugUtilsMessengerEXT(ctx.instance, ctx.debugMessenger, nullptr);
		vkDestroyInstance(ctx.instance,nullptr);
	}
}