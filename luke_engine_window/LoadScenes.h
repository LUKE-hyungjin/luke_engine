#pragma once
#include "..//luke_engine_source/SceneManager.h"

#include "PlayScene.h"
#include "TitleScene.h"

namespace luke {
	void LoadScene() {
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}