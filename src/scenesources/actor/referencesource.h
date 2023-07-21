#pragma once 


#include <nlohmann/json.hpp>
#include "../../source.h"
#include "../../configurable.h"
#include "../../util.h"
namespace StrawberryFudge
{
    class ReferenceActorSource : public SceneActorSource, public Configurable
    {
        public: 

        std::vector<Actor*> Actors; 

        static ReferenceActorSource ParseJson(nlohmann::json json); 

        void Configure(std::vector<std::string>& raw) override; 

        void GetActors(std::vector<Actor*>& actors) override; 
    };
}