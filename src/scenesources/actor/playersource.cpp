#include "playersource.h"


namespace StrawberryFudge 
{

    void PlayerSource::GetActors(std::vector<Actor *> &actors)
    {
        Actor* player = PlayerCharacter::GetSingleton(); 
        if (!player) return; 
        actors.emplace_back(player); 
    }

}