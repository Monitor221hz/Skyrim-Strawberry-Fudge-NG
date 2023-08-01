#pragma once 

#include "solution.h"

using namespace RE; 
namespace StrawberryFudge
{


    class Hook
    {

        public: 

        static void InstallDialogueHook()
        {
            REL::Relocation<std::uintptr_t> characterVtbl{ RE::VTABLE_Character[0] }; //0x4C
            _UpdateDialogue = characterVtbl.write_vfunc(0x4C, UpdateDialogue); 

            SKSE::log::info("Dialogue hook installed"); 
        }


        static void InstallResponseHook()
        {
            auto& trampoline = SKSE::GetTrampoline(); 
            SKSE::AllocTrampoline(16); 
            REL::Relocation<std::uintptr_t> target { REL::RelocationID(34429, 35249)} ; 
            _ConstructResponse = trampoline.write_call<5>(target.address() + REL::Relocate(0xDE, 0xDE), ConstructResponse); 

        }

        static void InstallVoiceFileHook()
        {
            auto& trampoline = SKSE::GetTrampoline(); 
            SKSE::AllocTrampoline(16); 
            REL::Relocation<std::uintptr_t> target { REL::RelocationID(24991,0)} ; 
            _GetVoiceFilePath = trampoline.write_call<5>(target.address() + REL::Relocate(0xB4, 0), GetVoiceFilePath); 
        }

        static inline std::unordered_map<TESTopic*, Solution*> TopicSolutions; 
        static inline std::unordered_map<TESTopicInfo*, Solution*> TopicInfoSolutions; 

        
        private:

        static bool UpdateDialogue(Actor* a_actor, DialogueResponse* a_response, bool a_unused); 


        static bool ConstructResponse(uint64_t unk01, char* a_filePath, BGSVoiceType* a_voiceType, TESTopic* a_topic, TESTopicInfo* a_topicInfo);


        static bool GetVoiceFilePath(uint64_t unk01, char* a_outPath, char* a_dataPath, char* a_pluginName, char* a_voiceName, char* a_voiceFileName, char* fileExtension); 


        static inline REL::Relocation<decltype(GetVoiceFilePath)> _GetVoiceFilePath; 


        static inline REL::Relocation<decltype(ConstructResponse)> _ConstructResponse; 

        static inline REL::Relocation<decltype(UpdateDialogue)> _UpdateDialogue;

        static inline std::string piss = "Piss.esp"; 
        

    };

}