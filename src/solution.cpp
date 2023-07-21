#include "solution.h"



namespace StrawberryFudge
{
    int Solution::Run()
    {
        int threadID = -1;

        std::vector<Actor*> actors; 
        for(auto* actorSource : ActorSources)
        {
            actorSource->GetActors(actors); 
        }
        for(auto* actor: actors)
        {
            SKSE::log::info("Captured actor {}", actor->GetName()); 
        }


        SKSE::log::info("Player character {:X}", PlayerCharacter::GetSingleton()->GetFormID()); 
        std::string animation = AnimationSource ? AnimationSource->GetAnimation() : "";  

        // msQ->AddMessage(DialogueMenu::MENU_NAME, UI_MESSAGE_TYPE::kHide, nullptr); 

        // auto* hulda = TESForm::LookupByID(0x1A66E)->As<Actor>(); 
        

        SKSE::log::info("Trying to start solution"); 

        auto* api = OstimNG_API::Scene::GetAPI(); 
        OstimNG_API::Scene::APIResult result = FurnitureSource ? api->StartScene("Strawberry Fudge"sv, FurnitureSource->GetFurniture(), animation.c_str(), actors, &threadID) : api->StartScene("Strawberry Fudge"sv, animation.c_str(), actors, &threadID); 
        if (result == OstimNG_API::Scene::APIResult::OK) 
        {
            SKSE::log::info("Solution ran successfully");
        }
        else 
        {
            SKSE::log::info("Solution failed to run"); 
        }

        
        return threadID; 
    }
}