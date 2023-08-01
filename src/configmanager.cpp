#include "configmanager.h"
#include "hook.h"


namespace StrawberryFudge 
{

    void ConfigManager::LoadActorSourceConfigs()
    {

        std::vector<std::string> files = SystemUtil::File::GetConfigs(R"(Data\StrawberryFudge\Sources)", "ACTR_SRC", ".json"sv);

        for (auto path: files)
        {
            std::ifstream reader;
            reader.open(path);
            nlohmann::json configData; 
            reader >> configData; 
            try 
            {
                ParseActorSourceConfig(configData); 
            }
            catch(...)
            {
                SKSE::log::warn("Failed to parse source file {}", path); 
            }
            
            reader.close(); 
            // for (auto configIt = configData.begin(); configIt != configData.end(); ++configIt) 
            // {

            //     auto lookup = (*configIt).find("Keys"); 
            // }
        }
    }

    void ConfigManager::LoadSolutionConfigs()
    {
        std::vector<std::string> files = SystemUtil::File::GetConfigs(R"(Data\StrawberryFudge)", "SLT", ".json"sv);

        for (auto path: files)
        {
            std::ifstream reader;
            reader.open(path);
            nlohmann::json configData; 
            try 
            {
                reader >> configData; 
                ParseSolution(configData); 
            }
            catch(...)
            {
                SKSE::log::warn("Failed to parse solution file {}", path); 
            }
            
            reader.close(); 
            // for (auto configIt = configData.begin(); configIt != configData.end(); ++configIt) 
            // {

            //     auto lookup = (*configIt).find("Keys"); 
            // }
        }
    }

    void ConfigManager::ParseActorSourceConfig(nlohmann::json json)
    {
        std::vector<std::string> rawStringData; 
        for(auto& jsonObject : json)
        {
            std::string sourceTypeString = jsonObject["type"]; 

            if (sourceTypeString == "alias")
            {
                AliasActorSource source = AliasActorSource::ParseJson(jsonObject);
                auto *sourcePtr = &aliasActorSources.emplace_back(source);
                actorSourceLookup.emplace(jsonObject["sourceName"], sourcePtr);
            }
            else if (sourceTypeString == "reference")
            {
                ReferenceActorSource source = ReferenceActorSource::ParseJson(jsonObject);
                auto *sourcePtr = &(defaultActorSources.emplace_back(source));
                actorSourceLookup.emplace(jsonObject["sourceName"], sourcePtr);
            }
        }

    }
    void ConfigManager::ParseSolution(nlohmann::json json)
    {
        // if (!json.contains("name") || !json["name"].is_string() || !json.contains("trigger") || !json["trigger"].is_string()) return; 
        for(auto& jsonObject : json)
        {
            std::vector<SceneActorSource *> actorSources;
            // SceneFurnitureSource* furnitureSource;
            // SceneAnimationSource* animationSource;

            // if (!json.contains("actorSources") || !json["actorSources"].is_array()) return;

            auto &actorSourceArray = jsonObject["actorSources"];
            for (auto actorSourceName : actorSourceArray)
            {
                std::string name = actorSourceName;
                if (!actorSourceLookup.contains(name))
                    continue;
                actorSources.emplace_back(actorSourceLookup[name]);
            }

            auto *triggerForm = FormUtil::Form::GetFormFromConfigString(jsonObject["trigger"]);

            switch (triggerForm->GetFormType())
            {
            case (FormType::Info):
            {
                auto *topicInfo = triggerForm->As<TESTopicInfo>();
                auto *solutionPtr = &solutions.emplace_back(Solution(actorSources, nullptr, nullptr));
                Hook::TopicInfoSolutions.emplace(topicInfo, solutionPtr);
            }
            break;

            case (FormType::Dialogue):
            {
                auto *topic = triggerForm->As<TESTopic>();
                auto *solutionPtr = &solutions.emplace_back(Solution(actorSources, nullptr, nullptr));
                Hook::TopicSolutions.emplace(topic, solutionPtr);
            }
            break;
            }
        }
        

    }
}