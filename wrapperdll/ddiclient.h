#pragma once
#include <ddi.hpp>
#include <ritms_dps.hpp>

#include "CallbackDispatcher.hpp"
#include "dllexport.h"

namespace HkbClient {

    typedef bool (__stdcall *AuthErrorCallbackFunction)(const char* errorMessage);

	extern "C" {
	    WDLL_EXPORT CallbackDispatcher* CreateDispatcher(
			ConfigRequestCallbackFunction configRequest, 
			DeploymentActionCallbackFunction deploymentAction, 
			CancelActionCallbackFunction cancelAction);
		WDLL_EXPORT void AddConfigAttribute(ddi::ConfigResponseBuilder* responseBuilder, const char* key, const char* value);
		WDLL_EXPORT void DownloadArtifact(ddi::Artifact* artifact, const char* location);
		WDLL_EXPORT void RunClient(const char* clientCertificate, const char* provisioningEndpoint, const char* xApigToken, CallbackDispatcher* dispatcher, AuthErrorCallbackFunction authErrorAction);
	    WDLL_EXPORT void DeleteDispatcher(CallbackDispatcher* dispatcher);
	}
}
