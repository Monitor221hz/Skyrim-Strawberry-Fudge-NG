#pragma once 

#include "../../source.h"
#include "../../util.h"


namespace StrawberryFudge
{
    class PlayerSource : public SceneActorSource
    {
    public:
        void GetActors(std::vector<Actor *> &actors) override;
    };
}