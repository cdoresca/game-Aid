#include "platform.h"

platform::platform(){
    init();
}

platform::~platform(){
    cleanup();
}

void platform::init(){
    m_window = new window();

    std::vector<const char*> deviceExtensions = {
		VK_KHR_SWAPCHAIN_EXTENSION_NAME,
		VK_KHR_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME
	};

	std::vector<PhysicalDeviceFeature> featureBasic = {
		{ "geometryShader", &VkPhysicalDeviceFeatures::geometryShader },
		{ "samplerAnisotropy", &VkPhysicalDeviceFeatures::samplerAnisotropy }
	};

	VkPhysicalDeviceBufferDeviceAddressFeatures bufferAddressFeatures {};
	bufferAddressFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES;
	bufferAddressFeatures.bufferDeviceAddress = VK_TRUE;
	
	VkPhysicalDeviceFeatures2 feature{};
	feature.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2;

    add(feature, reinterpret_cast<VkBaseOutStructure*>(&bufferAddressFeatures));

    vulkanContextBuilder ctxBuilder(m_window->get(),featureBasic,deviceExtensions,feature);
    director<VkContext> dir(&ctxBuilder);
    dir.make();
    ctx = ctxBuilder.get();
}

void platform::cleanup(){
    destroyVkContext(ctx);
    delete m_window;
}


GLFWwindow* platform::getGLFW(){ return m_window->get();}

VkContext platform::getContext(){return ctx;}