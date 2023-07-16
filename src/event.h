#pragma once

using namespace RE; 
using EventResult = BSEventNotifyControl; 

namespace StrawberryFudge
{
    class QuestEventHandler  : public BSTEventSink<TESQuestStartStopEvent>
    {
        public: 
        static QuestEventHandler* GetSingleton()
        {
            static QuestEventHandler singleton; 
            return &singleton; 
        }


        static void Register()
        {
            ScriptEventSourceHolder::GetSingleton()->GetEventSource<TESQuestStartStopEvent>()->AddEventSink(GetSingleton()); 
        }

        virtual EventResult ProcessEvent(const RE::TESQuestStartStopEvent *a_event, RE::BSTEventSource<RE::TESQuestStartStopEvent> *a_eventSource) override;

    };


    class StageEventHandler  : public BSTEventSink<TESQuestStageEvent>
    {
        public: 
        static StageEventHandler* GetSingleton()
        {
            static StageEventHandler singleton; 
            return &singleton; 
        }


        static void Register()
        {
            ScriptEventSourceHolder::GetSingleton()->GetEventSource<TESQuestStageEvent>()->AddEventSink(GetSingleton()); 
        }

        virtual EventResult ProcessEvent(const TESQuestStageEvent *a_event, RE::BSTEventSource<TESQuestStageEvent> *a_eventSource) override;

    };

}