#pragma once 

#include <nlohmann/json.hpp>
#include <unordered_map>


#include "util.h"

#include "source.h"
#include "solution.h"
#include "configurable.h"

#include "scenesources/actor/aliassource.h"
#include "scenesources/actor/referencesource.h"
#include "scenesources/actor/speakersource.h"
#include "scenesources/actor/playersource.h"
#include "scenesources/animation/namesource.h"

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


        static void LoadActorSourceConfigs(); 

        static void LoadSolutionConfigs(); 

        static void ParseActorSourceConfig(nlohmann::json json); 
        static void ParseSolution(nlohmann::json json); 



        static inline std::unordered_map<std::string, SceneActorSource*> actorSourceLookup; 



        static inline PlayerSource playerSource; 
        static inline SpeakerActorSource speakerSource; 


        static inline std::vector<NameAnimationSource> nameAnimationSources; 

        static inline std::vector<AliasActorSource> aliasActorSources; 
        static inline std::vector<ReferenceActorSource> defaultActorSources; 
        

        
        static inline std::vector<Solution> solutions;

        static void LoadStaticConfigs()
        {
            actorSourceLookup.emplace("SpeakerSource", (&speakerSource));
            actorSourceLookup.emplace("PlayerSource", (&playerSource));
        }
    };



}