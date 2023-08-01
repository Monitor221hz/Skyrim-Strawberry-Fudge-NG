#include "log.h"
#include "hook.h"
#include "event.h"
#include "configmanager.h"
#include "../extern/OstimNG-API-Scene.h"
using namespace StrawberryFudge; 
void OnDataLoaded()
{
   
}

void MessageHandler(SKSE::MessagingInterface::Message* a_msg)
{
	switch (a_msg->type) {
	case SKSE::MessagingInterface::kDataLoaded:
        QuestEventHandler::Register(); 
		StageEventHandler::Register(); 
		ConfigManager::LoadAllConfigs();  
		
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
	// if (skse->RuntimeVersion() == SKSE::RUNTIME_SSE_LATEST_SE) Hook::InstallVoiceFileHook(); 
	StrawberryFudge::Hook::InstallDialogueHook(); 
	// StrawberryFudge::Hook::InstallResponseHook(); 
	
    return true;
}