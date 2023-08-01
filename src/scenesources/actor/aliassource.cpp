#include "aliassource.h"

namespace StrawberryFudge 
{
    void AliasActorSource::GetActors(std::vector<Actor*>& actors)
    {
        RE::BSWriteLockGuard AliasLock(owningQuest->aliasAccessLock);

        for (auto *alias : baseAliases)
        {
            auto handle = owningQuest->refAliasMap.find(alias->aliasID);
            if (handle == owningQuest->refAliasMap.end())
                continue;
            auto *refr = handle->second.get().get();

            if (!refr || refr->GetBaseObject()->GetFormType() != FormType::NPC) continue;

            actors.emplace_back(refr->As<Actor>());
        }
        
    }

    /// @brief 
    /// @param raw[0] Quest FormID~PluginName
    /// @param raw[>0] Alias Name 
    void AliasActorSource::Configure(std::vector<std::string> &raw)
    {
        try 
        {
            owningQuest = FormUtil::Form::GetFormFromConfigString(raw[0])->As<TESQuest>();
            SKSE::log::info("Quest {} loaded from entry {}", owningQuest->GetName(), raw[0]); 
            if (!owningQuest) throw; 

            for(auto &str : raw | std::views::drop(1))
            {
                auto* alias = FindAliasByName(str); 
                if (alias) baseAliases.emplace_back(alias); 
            }

            

        }
        catch(...)
        {
            SKSE::log::info("Failed to parse quest entry {}", raw[0]); 
        }
    }

    AliasActorSource AliasActorSource::ParseJson(nlohmann::json json)
    {
            std::vector<std::string> rawStringData; 
            AliasActorSource source; 

            
            // if (!jsonSource.contains("questRecord") || !jsonSource["questRecord"].is_string()) return source; 
            rawStringData.emplace_back(json["quest"]); 

            // if (!jsonSource.contains("aliasNames") || !jsonSource["aliasNames"].is_array()) return source; 
            auto &jsonAliasArray = json["aliasNames"]; 

            for(auto& jsonAlias : jsonAliasArray)
            {
                if (!jsonAlias.is_string()) continue; 
                rawStringData.emplace_back(jsonAlias); 
            } 

            source.Configure(rawStringData); 
            return source; 
    }

    BGSBaseAlias* AliasActorSource::FindAliasByName(std::string_view name)
    {
        RE::BSWriteLockGuard AliasLock{owningQuest->aliasAccessLock};
        for (auto *alias : owningQuest->aliases)
        {
            std::string aliasName = alias->aliasName.c_str();
            SKSE::log::info("Checking alias {}", aliasName) ;
            if (aliasName != name) continue;
            SKSE::log::info("Alias {} loaded", aliasName);
            return alias;
        }
        return nullptr;
    }
}