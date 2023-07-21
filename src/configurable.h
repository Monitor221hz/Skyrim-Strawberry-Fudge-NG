#pragma once 

namespace StrawberryFudge
{
    class Configurable 
    {

        public: 
        virtual void Configure(std::vector<std::string>& raw) =0; 
    };
    
}