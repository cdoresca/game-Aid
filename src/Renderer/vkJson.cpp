#include "vkJson.h"
#include "vkDebug.h"


void from_json(const core::json& j, VkApplicationInfo& info){
    info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    
    info.pApplicationName = j.value("pApplicationName", "").c_str();
    info.pEngineName = j.value("pEngineName", "").c_str();
    uint32_t version[4];
    j.at("engineVersion").get_to(version);
    info.engineVersion = VK_MAKE_API_VERSION(version[0],version[1],version[2],version[3]);
    info.apiVersion = VK_API_VERSION_1_3;
    
}

void from_json(const core::json& j, VkInstanceCreateInfo& info){
    info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    j.at("enabledExtensionCount").get_to(info.enabledExtensionCount);
    j.at("enabledLayerCount").get_to(info.enabledLayerCount);
    info.ppEnabledExtensionNames = j.value("ppEnabledExtensionNames", nullptr);
    info.ppEnabledLayerNames = j.value("ppEnabledLayerNames", nullptr);
}



void from_json(const core::json& j, VkDeviceCreateInfo& info){
    info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    info.enabledLayerCount = j.value("enabledLayerCount",0);
    info.ppEnabledLayerNames = j.value("ppEnabledLayerNames", nullptr);
    info.enabledExtensionCount = j.value("enabledExtensionCount",0);
    info.ppEnabledExtensionNames = j.value("ppEnabledExtensionNames",nullptr);
}


void from_json(const core::json& j, VkValidationFeaturesEXT& info){
    info.sType = VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT;
    info.enabledValidationFeatureCount = j.value("enabledValidationFeatureCount", 0);
    info.pEnabledValidationFeatures = j.value("pEnabledValidationFeatures", nullptr);
    info.disabledValidationFeatureCount = j.value("disabledValidationFeatureCount",0);
    info.pDisabledValidationFeatures = j.value("pDisabledValidationFeatures", nullptr);
    info.pNext = j.value("pNext", nullptr);
}

void from_json(const core::json& j, VkDebugUtilsMessengerCreateInfoEXT& info){
    info.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;

    auto get = [j,info](const char* name){
        uint32_t cpt  = 0;
        std::vector<uint32_t> list;
        j.at(name).get_to(list);
        for(size_t i = 0; i < list.size(); i++)
            cpt |= list[i];
        return cpt;
    };

    info.messageSeverity = get("messageSeverity");
    info.messageType = get("messageType");
    info.pfnUserCallback = debugCallback;
    info.pUserData = j.value("pUserData", nullptr);
    info.flags = j.value("flags", 0);
    info.pNext = j.value("pNext", nullptr);
}

void from_json(const core::json& j, VkSwapchainCreateInfoKHR& info){

    info.minImageCount = j.value("minImageCount", 0);
    info.imageFormat = j.value("format", VK_FORMAT_UNDEFINED);
    info.imageColorSpace = j.value("colorSpace", VK_COLOR_SPACE_SRGB_NONLINEAR_KHR);
    info.imageArrayLayers = j.value("imageArrayLayers", 0);
    info.imageUsage = j.value("imageUsage", 0);
    info.preTransform = j.value("preTransform", VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR);
    info.compositeAlpha = j.value("compositeAlpha",VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR);
    info.presentMode = j.value("presentMode", VK_PRESENT_MODE_IMMEDIATE_KHR);
    info.clipped = j.value("clipped", true);
    info.imageSharingMode = j.value("imageSharingMode", VK_SHARING_MODE_EXCLUSIVE);

}