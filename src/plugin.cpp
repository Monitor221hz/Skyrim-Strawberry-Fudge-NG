#include "log.h"
#include "../extern/OstimNG-API-Scene.h"

void OnDataLoaded()
{
   
}

void MessageHandler(SKSE::MessagingInterface::Message* a_msg)
{
	switch (a_msg->type) {
	case SKSE::MessagingInterface::kDataLoaded:
        
		break;
	case SKSE::MessagingInterface::kPostLoad:

		break;
	case SKSE::MessagingInterface::kPreLoadGame:
		break;
	case SKSE::MessagingInterface::kPostLoadGame:
        break;
	case SKSE::MessagingInterface::kNewGame:
		break;
	}
}

SKSEPluginLoad(const SKSE::LoadInterface *skse) {
    SKSE::Init(skse);
	SetupLog();


    auto messaging = SKSE::GetMessagingInterface();
	if (!messaging->RegisterListener("SKSE", MessageHandler)) {
		return false;
	}
	OstimNG_API::Scene::GetAPI(); 
	if (g_ostimSceneInterface) 
	{
		SKSE::log::info("Ostim API successfully acquired"); 
	}
	else 
	{
		SKSE::log::info("Failed to acquire Ostim API"); 
	}
    return true;
}