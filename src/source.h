#pragma once 

using namespace RE; 
#include "../extern/OstimNG-API-Scene.h"


namespace StrawberryFudge
{
    class SceneActorSource 
    {
        public: 

        virtual void GetActors(std::vector<Actor*>& actors) = 0; 
    };

    class SceneFurnitureSource 
    {
        public: 

        virtual TESObjectREFR* GetFurniture() =0; 
    };

    class SceneAnimationSource 
    {
        public: 

        virtual std::string& GetAnimation() =0; 

    };  

}