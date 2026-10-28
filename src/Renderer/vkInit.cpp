#include "vkInit.h"
#include "asserts.h"
#include "vkJson.h"
#include "vkQuery.h"
#include <set>
#include "swapChainSupportDetail.h"
#include "queueFamily.h"
#include "vkStruct.h"

namespace renderer{

    
    void createInstance(const core::json& j, VkContext& ctx){
        
        VkInstanceCreateInfo createInfo = j.get<VkInstanceCreateInfo>();
    
        if (enableValidationLayers){
            VkDebugUtilsMessengerCreateInfoEXT debug = j.get<VkDebugUtilsMessengerCreateInfoEXT>();
            createInfo.pNext =  (VkDebugUtilsMessengerCreateInfoEXT*)&debug;}
        
        VK_CHECK(vkCreateInstance(&createInfo, nullptr, &ctx.instance));
    }
    
    void createSurface(VkContext& ctx,window window_){
        VK_CHECK(glfwCreateWindowSurface(ctx.instance, window_.get(), nullptr, &ctx.surface));
    }

    bool isExtensionSuitable(const core::json& j, VkPhysicalDevice pdevice){
	    std::vector<VkExtensionProperties> availableExtensions = vkQuery::queryVkEnumerateDeviceExtensionProperties(pdevice);
        std::set<std::string> deviceExtension = j["device"]["ppEnabledExtensionNames"];
        for(size_t i = 0; i < availableExtensions.size(); i++)
            deviceExtension.erase(availableExtensions[i].extensionName);

        return deviceExtension.empty();
    }

    bool isSwapChainSuitable(const VkContext& ctx){
        SwapChainSupportDetails detail = querySwapChainSupport(ctx);
        return !detail.formats.empty() && !detail.presentsModes.size(); 
    }

    bool isSuitable(const core::json& j, const VkContext& ctx){
        return isExtensionSuitable(j, ctx.physicalDevice) && isSwapChainSuitable(ctx);
    }

    bool isFeatureSuitable(const core::json& j, const VkContext& ctx){
        VkPhysicalDeviceFeatures2 supported{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2};
        
        //TODO
    }

    std::vector<VkPhysicalDevice>  choosePhysicalDevice(const core::json& j, VkContext& ctx){
        std::vector<VkPhysicalDevice> devices = vkQuery::queryVkEnumeratePhysicalDevices(ctx.instance);
        std::vector<VkPhysicalDevice> chosen;
        for(size_t i = 0; i < devices.size(); i++){
            ctx.physicalDevice = devices[i];
            if(isSuitable(j,ctx)) chosen.push_back(devices[i]);   
        }
        ctx.physicalDevice = chosen[0];
        return chosen; 
    }

    VkDeviceQueueCreateInfo& chooseVkQueueFamily(const VkContext& ctx){
        std::vector<QueueFamiliesIndices> indices = findQueueFamilies(ctx);
        VkDeviceQueueCreateInfo info;
       for(size_t i = 0; i < indices.size(); i++){
            if(!indices[i].isComplete())
                continue;
            float priority = 1.0f;
            info = vkStruct::getVkDeviceQueueCreateInfo(indices[i].graphicFamily.value(), 1 ,&priority);
            //count est 1 savoir comment gerer le tableau de priority queue et plusieurs queue
       }
       return info;
    }

    void createDevice(const core::json& j, VkContext& ctx){
        VkDeviceQueueCreateInfo infoQueue = chooseVkQueueFamily(ctx);

        VkDeviceCreateInfo info = j.get<VkDeviceCreateInfo>();
        info.queueCreateInfoCount = 1;
        info.pQueueCreateInfos = &infoQueue;

        VK_CHECK(vkCreateDevice(ctx.physicalDevice, &info, nullptr, &ctx.device));
        vkGetDeviceQueue(ctx.device, infoQueue.queueFamilyIndex, 0, &ctx.queue);
    }

}