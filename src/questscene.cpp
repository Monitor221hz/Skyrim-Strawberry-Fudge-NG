#include "questscene.h"

namespace StrawberryFudge
{


    
    void BakedScene::Load()
    {
        Aliases.clear(); 
        for(auto str: AliasNames)
        {
            auto* alias = FindAliasByName(str); 
            if (alias) Aliases.emplace_back(alias); 
        }
    }

    void BakedScene::Start()
    {
        using Result = OstimNG_API::Scene::APIResult; 

        auto result = OstimNG_API::Scene::GetAPI()->StartScene("StrawberryFudge"sv, "", GetActors(), ThreadID);

        result == Result::OK ? SKSE::log::info("Scene started successfully") : SKSE::log::info("Scene start failed");
    }
    std::vector<Actor *> BakedScene::GetActors()
    {
        RE::BSWriteLockGuard AliasLock{Quest->aliasAccessLock};
        std::vector<Actor*> actors = Actors; 

        for (auto *alias : Aliases)
        {
            auto handle = Quest->refAliasMap.find(alias->aliasID);
            if (handle == Quest->refAliasMap.end())
                continue;
            auto *refr = handle->second.get().get();

            if (!refr || refr->GetFormType() != FormType::ActorCharacter)
                continue;

            actors.emplace_back(refr->As<Actor>());
        }
        return actors; 
        
    }

    BGSBaseAlias *BakedScene::FindAliasByName(std::string_view name)
    {
        RE::BSWriteLockGuard AliasLock{ Quest->aliasAccessLock };
            for(auto* alias : Quest->aliases)
            {
                std::string aliasName = alias->aliasName.c_str(); 
                if (aliasName == name) return alias; 
                
            }
            return nullptr; 
    }
}