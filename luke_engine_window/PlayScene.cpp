#include "PlayScene.h"
#include "GameObject.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"

namespace luke {
	PlayScene::PlayScene() {

	}
	PlayScene::~PlayScene() {

	}
	void PlayScene::Initialize() {
		{
			Player* bg = new Player();
			Transform* tr
				= bg->AddComponent<Transform>();
			tr->SetPos(Vector2(0, 0));

			tr->SetName(L"TR");

			SpriteRenderer* sr
				= bg->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			sr->ImageLoad(L"D:\\dev\\luke_engine\\Resources\\CloudOcean.png");


			AddGameObject(bg);
		}
	}
	void PlayScene::Update() {
		Scene::Update();

	}
	void PlayScene::LateUpdate() {
		Scene::LateUpdate();
	}
	void PlayScene::Render(HDC hdc) {
		Scene::Render(hdc);
	}
}