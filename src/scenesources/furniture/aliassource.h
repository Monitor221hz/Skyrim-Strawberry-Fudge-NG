// #pragma once 

// #include <nlohmann/json.hpp>
// #include "../../source.h"
// #include "../../configurable.h"

// #include "../../util.h"



// namespace StrawberryFudge 
// {
//     class AliasFurnitureSource : SceneFurnitureSource, Configurable
//     {
//         public: 


//         TESObjectREFR* GetFurniture() override; 

//         void Configure(std::vector<std::string>& raw) override; 

//         static AliasFurnitureSource ParseJson(nlohmann::json json);  


//         private: 

//         TESQuest* owningQuest; 
//         BGSBaseAlias* baseAlias; 


//         BGSBaseAlias* FindAliasByName(std::string_view name); 

//     };
// }