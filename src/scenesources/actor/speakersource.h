#pragma once


#include "../../source.h"
#include "../../util.h"


namespace StrawberryFudge
{
class SpeakerActorSource : public SceneActorSource
{
    public: 

    void GetActors(std::vector<Actor*>& actors) override; 

};
}