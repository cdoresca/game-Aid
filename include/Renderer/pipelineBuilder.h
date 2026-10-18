#pragma once
#include "../IBuilder.h"
#include "pipeline.h"

namespace renderer{

    class pipelineBuilder:public IBuilder<Pipeline>
    {
        public:
            pipelineBuilder();
            ~pipelineBuilder();

            void reset() override {pipeline={};};
            Pipeline get() override { return pipeline;};
        private:
            Pipeline pipeline;
        
    };
    
    
    
}