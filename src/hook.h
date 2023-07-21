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

        static inline std::unordered_map<TESTopic*, Solution*> TopicSolutions; 
        static inline std::unordered_map<TESTopicInfo*, Solution*> TopicInfoSolutions; 

        
        private:

        static bool UpdateDialogue(Actor* a_actor, DialogueResponse* a_response, bool a_unused); 

        static inline REL::Relocation<decltype(UpdateDialogue)> _UpdateDialogue;

        
        

    };
}