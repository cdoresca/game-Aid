#pragma once

#include <vector>

#include "window.h"
#include "vkContext.h"
#include "../IBuilder.h"
#include "physicalDeviceInformation.h"


namespace renderer{

class vulkanContextBuilder: public IBuilder<VkContext>
{
    public:
    
        vulkanContextBuilder(window window,const std::vector<PhysicalDeviceFeature>& featureBasic, std::vector<const char*> deviceExtensions, VkPhysicalDeviceFeatures2 features2);
        
        void reset() override;
        void build() override;

        VkContext get() override;

    private:
        VkContext context;
        window window_;

        VkPhysicalDeviceFeatures2 features2;

        std::vector<const char*> deviceExtensions;
        std::vector<PhysicalDeviceFeature> featureBasic;

        float priorityQueue = 1.0f;

        
        bool isDeviceSuitable(const VkPhysicalDevice& gpu);
        bool isFeatureSuitable(const VkPhysicalDeviceFeatures& features) const;
        bool isQueueSuitable(const VkPhysicalDevice& gpu) const;
        bool isSwapChainSuitable(const VkPhysicalDevice& gpu) const;
        bool isExtensionSuitable(const VkPhysicalDevice& gpu) const;
        bool isModernFeatureSuitable(const VkPhysicalDevice& gpu);
        
        void createInstance();
        void setupDebugMessenger();
        void createSurface();
        void choosePhysicalDevice();
        void createDevice();
        void createInfoQueue(std::vector<VkDeviceQueueCreateInfo>& info);
        void createQueue();
    
};

}