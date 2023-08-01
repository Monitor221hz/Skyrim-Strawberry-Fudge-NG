#include "solution.h"



namespace StrawberryFudge
{
    int Solution::Run()
    {
        uint32_t threadID = -1;

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
        TESObjectREFR* furniture = FurnitureSource ? FurnitureSource->GetFurniture() : nullptr; 
        // msQ->AddMessage(DialogueMenu::MENU_NAME, UI_MESSAGE_TYPE::kHide, nullptr); 

        // auto* hulda = TESForm::LookupByID(0x1A66E)->As<Actor>(); 

        int numActors = actors.size(); 

        constexpr const char* pluginName = "Strawberry Fudge"; 
        // Actor* actorArray[256]; 
        // std::copy(actors.begin(), actors.end(), actorArray); 
        SKSE::log::info("Trying to start solution"); 
        
        auto* api = OstimNG_API::Scene::GetAPI(); 
        if (!api) 
        {
            SKSE::log::warn("Could not communicate with Ostim API. Solution could not be started"); 
            return -1; 
        }
        OstimNG_API::Scene::APIResult result; 

        switch (numActors)
        {
            case 2: 
            result = api->StartCoupleScene(pluginName, furniture, animation.c_str(), actors[0], actors[1], &threadID);
            break;
            case 3: 
            result = api->StartThreesomeScene(pluginName, furniture, animation.c_str(), actors[0], actors[1], actors[2], &threadID);
            break; 
            case 4: 
            result = api->StartFoursomeScene(pluginName, furniture, animation.c_str(), actors[0], actors[1], actors[2], actors[3], &threadID);
            break;
            default: 
            {
                Actor* actorArray[256]; 
                std::copy(actors.begin(), actors.end(), actorArray); 
                result = api->StartScene(pluginName, furniture, animation.c_str(), actorArray, &threadID); 
            }
            break;
        }
        
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