#pragma once 

#include <nlohmann/json.hpp>
#include "../../source.h"
#include "../../configurable.h"

#include "../../util.h"



namespace StrawberryFudge 
{
    class AliasActorSource : public SceneActorSource , public Configurable
    {
        public: 


        void GetActors(std::vector<Actor*>& actors) override; 

        void Configure(std::vector<std::string>& raw) override; 

        static AliasActorSource ParseJson(nlohmann::json json);  


        private: 

        TESQuest* owningQuest; 
        std::vector<BGSBaseAlias*> baseAliases; 


        BGSBaseAlias* FindAliasByName(std::string_view name); 


        
    };
}