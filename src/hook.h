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
//char __fastcall sub_14038DF40(int64 a1, char *a2, char *a3, char *a4, char *Src, char *a6, char *a7) 
//Up	p	sub_14038DE50+B4	call    sub_14038DF40




//char __fastcall sub_14038DE50(void *a1, char *a2, BGSVoiceType *a3, TESTopic *a4, TESTopicInfo *a5) AE sub_1403A43D0
//SE Down	p	sub_14056D570+DE	call    sub_14038DE50 (34429, 35249)
//AE Down	p	sub_140589FE0+DE	call    sub_1403A43D0

        static inline REL::Relocation<decltype(ConstructResponse)> _ConstructResponse; 

        static inline REL::Relocation<decltype(UpdateDialogue)> _UpdateDialogue;

        static inline std::string piss = "Piss.esp"; 
        

    };
    //Up	p	TESTopic__sub_14038F9A0+E2	call    sub_14056C9D0




    //ae: Up	p	sub_14056C9D0+E4	call    sub_14056D570
    //Down	p	sub_14056D570+DE	call    sub_14038DE50
    //Up	p	sub_14038DE50+B4	call    sub_14038DF40
}