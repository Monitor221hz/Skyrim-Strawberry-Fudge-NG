#include "referencesource.h"


namespace StrawberryFudge 
{
    void ReferenceActorSource::GetActors(std::vector<Actor*>& actors)
    {
        for(auto* actor: Actors)
        {
            actors.emplace_back(actor); 
        }
    }
    ReferenceActorSource ReferenceActorSource::ParseJson(nlohmann::json json)
    {
        ReferenceActorSource source; 
        std::vector<std::string> rawStringData; 

        auto &jsonRefArray = json["actorRecords"];
        for (auto &jsonRecord : jsonRefArray)
        {
            if (!jsonRecord.is_string())
                continue;
            rawStringData.emplace_back(jsonRecord);
        }
        source.Configure(rawStringData);

        return source; 
    }
    void ReferenceActorSource::Configure(std::vector<std::string> &raw)
    {
        for(auto& str : raw)
        {
            try 
            {
                auto* actor = FormUtil::Form::GetFormFromConfigString(str)->As<Actor>(); 
                SKSE::log::info("Actor Reference {} loaded from entry {}", actor->GetName(), str); 
                if (actor) Actors.emplace_back(actor); 
            }
            catch(...)
            {
                SKSE::log::info("Failed to parse record entry {}", str); 
            }
        }
    }
}