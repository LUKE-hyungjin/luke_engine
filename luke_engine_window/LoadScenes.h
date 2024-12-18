#pragma once
#include "..//luke_engine_source/SceneManager.h"

#include "PlayScene.h"

namespace luke {
	void LoadScene() {
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}