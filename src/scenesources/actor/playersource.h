#pragma once 

#include "../../source.h"
#include "../../util.h"


namespace StrawberryFudge
{
    class PlayerSource : SceneActorSource
    {
    public:
        void GetActors(std::vector<Actor *> &actors) override;
    };
}