#pragma once
using namespace RE;
#include <unordered_set>
#include "../extern/OstimNG-API-Scene.h"
namespace StrawberryFudge
{
    struct BakedScene 
    {
        public: 


        BakedScene(TESQuest* a_quest, std::vector<std::string> a_aliasNames, std::vector<Actor*> a_actors)
        : Quest(a_quest), AliasNames(a_aliasNames), Actors(a_actors)
        {
            Load(); 
        }
        void Load();
        void Start();

        private:

        TESQuest* Quest; 
        std::vector<std::string> AliasNames; 
        int ThreadID; 
        std::vector<BGSBaseAlias*> Aliases; 


        std::vector<Actor*> AliasActors; 
        std::vector<Actor*> Actors; 
        
        

        BGSBaseAlias* FindAliasByName(std::string_view name);
        
        Actor* GetActorFromAlias(); 
        std::vector<Actor*> GetActors();

        
    };
}