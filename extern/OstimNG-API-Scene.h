#pragma once 
using namespace RE; 

namespace OstimNG_API::Scene
{
    
    enum class InterfaceVersion : uint8_t
    {
        V1

    };
    
    
    enum class APIResult : uint8_t
    {
        // Scene successfully started
        OK,

        // The arguments were invalid
        Invalid,

        // Failed 
        Failed
    };
    class ISceneInterface
    {
        public:
        
            /// @brief
            /// Start a scene with optionally specified furniture reference.
            /// @return
            [[nodiscard]] virtual APIResult StartScene(const char* pluginName, RE::TESObjectREFR* furniture,
                                                       const char* startingAnimation, Actor* actors[256], uint32_t* threadID) noexcept = 0;


            [[nodiscard]] virtual APIResult StartCoupleScene(const char* pluginName, TESObjectREFR* furniture, const char* startingAnimation, Actor* dom, Actor* sub, uint32_t* threadID) noexcept = 0; 

            [[nodiscard]] virtual APIResult StartThreesomeScene(const char* pluginName, TESObjectREFR* furniture, const char* startingAnimation, Actor* firstActor, Actor* secondActor, Actor* thirdActor, uint32_t* threadID) noexcept = 0; 

            [[nodiscard]] virtual APIResult StartFoursomeScene(const char* pluginName, TESObjectREFR* furniture, const char* startingAnimation, Actor* firstActor, Actor* secondActor, Actor* thirdActor, Actor* fourthActor, uint32_t* threadID) noexcept = 0; 
            /// @brief 
            /// Stop the specified scene.
            /// @param threadID integer ID of Ostim thread to stop. 
            /// @return 
            [[nodiscard]] virtual APIResult StopScene(const char* pluginName, uint32_t threadID) noexcept = 0;


            [[nodiscard]] virtual APIResult SetAutoMode(const char* pluginName, uint32_t threadID,
                                                        bool autoMode) noexcept = 0;


            [[nodiscard]] virtual APIResult TryGetAutoMode(const char* pluginName, uint32_t threadID,
                                                           bool* autoMode) noexcept = 0; 
        
        
    };

    
    using _RequestPluginAPI_Scene = ISceneInterface* (*)(InterfaceVersion a_interfaceVersion, const char* a_pluginName, REL::Version a_pluginVersion); 

    ISceneInterface* GetAPI();

}

extern OstimNG_API::Scene::ISceneInterface* g_ostimSceneInterface;