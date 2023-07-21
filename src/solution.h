#pragma once 

using namespace RE; 
#include "../extern/OstimNG-API-Scene.h"
#include "source.h"

namespace StrawberryFudge 
{
    
    class Solution 
    {
        
        public: 

        Solution(std::vector<SceneActorSource*> actorSources, SceneAnimationSource* animationSource,SceneFurnitureSource* furnitureSource )
        : ActorSources(actorSources), FurnitureSource(furnitureSource), AnimationSource(animationSource)
        {

        } 


        int Run(); 


        private: 
        std::vector<SceneActorSource*> ActorSources; 

        SceneFurnitureSource* FurnitureSource = nullptr;
        SceneAnimationSource* AnimationSource = nullptr;  
        
    };
}
