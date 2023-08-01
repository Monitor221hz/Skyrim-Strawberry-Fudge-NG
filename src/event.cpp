#include "event.h"


namespace StrawberryFudge
{
    EventResult QuestEventHandler::ProcessEvent(const RE::TESQuestStartStopEvent *a_event, RE::BSTEventSource<RE::TESQuestStartStopEvent> *a_eventSource)
    {
        if (!a_event->formID) return EventResult::kContinue; 
        
        // auto* quest = TESForm::LookupByID(a_event->formID)->As<TESQuest>(); 

        // a_event->started ? SKSE::log::info("Quest: {} started", quest->GetName()) : SKSE::log::info("Quest {} finished", quest->GetName()); 
        return EventResult::kContinue; 
    }
    EventResult StageEventHandler::ProcessEvent(const TESQuestStageEvent *a_event, RE::BSTEventSource<TESQuestStageEvent> *a_eventSource)
    {
        if (!a_event->formID) return EventResult::kContinue; 
        
        // auto* quest = TESForm::LookupByID(a_event->formID)->As<TESQuest>(); 

        // SKSE::log::info("Quest: {} Stage {}", quest->GetName(), a_event->stage); 

        return EventResult::kContinue; 
    }
}