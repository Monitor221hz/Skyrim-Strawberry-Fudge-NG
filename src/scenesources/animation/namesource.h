#pragma once 


#include "../../source.h"



namespace StrawberryFudge
{
    class NameAnimationSource : public SceneAnimationSource 
    {
        public: 
        NameAnimationSource(std::string animationName) : animation(animationName) {}


        std::string& GetAnimation() override; 

        private: 

        std::string animation; 
    };
}