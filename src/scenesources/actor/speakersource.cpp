#include "speakersource.h"



namespace StrawberryFudge
{
    void SpeakerActorSource::GetActors(std::vector<Actor *> &actors)
    {
        auto* topicManager = MenuTopicManager::GetSingleton(); 
        if (!topicManager) return; 

        auto* speakerRef = topicManager->speaker.get().get(); 

        if (!speakerRef || speakerRef->GetFormType() != FormType::ActorCharacter) return; 
        auto* speaker = speakerRef->As<Actor>(); 

        actors.emplace_back(speaker); 
    }
}