#pragma once
#include "..//luke_engine_source/SceneManager.h"

#include "LoadingScene.h"
#include "PlayScene.h"
#include "TitleScene.h"
#include "ToolScene.h"

namespace luke {
	void LoadScene() {
		SceneManager::CreateScene<LoadingScene>(L"LoadingScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<ToolScene>(L"ToolScene");

		SceneManager::LoadScene(L"LoadingScene");
	}
}