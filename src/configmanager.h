#pragma once 

#include <nlohmann/json.hpp>
#include <unordered_map>


#include "util.h"

#include "source.h"
#include "solution.h"
#include "configurable.h"

#include "scenesources/actor/aliassource.h"
#include "scenesources/actor/referencesource.h"

namespace StrawberryFudge 
{
    class ConfigManager 
    {

        public: 


        static void LoadAllConfigs()
        {
            LoadStaticConfigs(); 
            LoadActorSourceConfigs(); 
            LoadSolutionConfigs(); 

            SKSE::log::info("Found {} Source Files and {} Solutions", actorSourceLookup.size(), solutions.size()); 
        }

        private: 

        static void LoadStaticConfigs(); 

    
        static void LoadActorSourceConfigs(); 

        static void LoadSolutionConfigs(); 

        static void ParseActorSourceConfig(nlohmann::json json); 
        static void ParseSolution(nlohmann::json json); 



        static inline std::unordered_map<std::string, SceneActorSource*> actorSourceLookup; 


        static inline std::vector<AliasActorSource> aliasActorSources; 
        static inline std::vector<ReferenceActorSource> defaultActorSources; 
        
        static inline std::vector<Solution> solutions; 

        

    };



}