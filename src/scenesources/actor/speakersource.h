#pragma once

#include <nlohmann/json.hpp>
#include "../../source.h"
#include "../../configurable.h"
#include "../../util.h"


namespace StrawberryFudge
{
class SpeakerActorSource : public SceneActorSource
{
    public: 
    
    void GetActors(std::vector<Actor*>& actors) override; 

};
}