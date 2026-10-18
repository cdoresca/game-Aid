#pragma once
#include "../IBuilder.h"
#include "pipeline.h"

namespace renderer{

    class pipelineBuilder:public IBuilder<Pipeline>
    {
    private:
        /* data */
    public:
        pipelineBuilder(/* args */);
        ~pipelineBuilder();
    };
    
    pipelineBuilder::pipelineBuilder(/* args */)
    {
    }
    
    pipelineBuilder::~pipelineBuilder()
    {
    }
    
}