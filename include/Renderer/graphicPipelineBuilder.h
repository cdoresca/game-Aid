#pragma once
#include "pipelineBuilder.h"
#include "shader.h"
#include <vector>
namespace renderer{

    class graphicPipelineBuilder: public pipelineBuilder
    {
        public:
            graphicPipelineBuilder(/* args */);
            ~graphicPipelineBuilder();
            void build() override;

        private:
            VkPipelineShaderStageCreateInfo           pStages;
            VkPipelineVertexInputStateCreateInfo      pVertexInputState;
            VkPipelineInputAssemblyStateCreateInfo    pInputAssemblyState;
            VkPipelineTessellationStateCreateInfo     pTessellationState;
            VkPipelineViewportStateCreateInfo         pViewportState;
            VkPipelineRasterizationStateCreateInfo    pRasterizationState;
            VkPipelineMultisampleStateCreateInfo      pMultisampleState;
            VkPipelineDepthStencilStateCreateInfo     pDepthStencilState;
            VkPipelineColorBlendStateCreateInfo       pColorBlendState;
            VkPipelineDynamicStateCreateInfo          pDynamicState;

            



            
    };
    
}