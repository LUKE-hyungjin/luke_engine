#include "PlayScene.h"
#include "GameObject.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Input.h"
#include "TitleScene.h"
#include "SceneManager.h"
#include "Object.h"
#include "Texture.h"
#include "Resources.h"
#include "PlayerScript.h"
#include "Camera.h"
#include "Renderer.h"
#include "Animator.h"
#include "Cat.h"
#include "CatScript.h"
#include "BoxCollider2D.h"
#include "CollisionManager.h"

namespace luke {
	PlayScene::PlayScene() {

	}
	PlayScene::~PlayScene() {

	}
	void PlayScene::Initialize() {
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Animal, true);
		// main camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::Particle, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		PlayerScript* plScript = mPlayer->AddComponent<PlayerScript>();
		BoxCollider2D* collider = mPlayer->AddComponent<BoxCollider2D>();
		collider->SetOffset(Vector2(-50.0f, -50.0));
	
		graphcis::Texture* playerTex = Resources::Find<graphcis::Texture>(L"Player");
		Animator* playerAnimator = mPlayer->AddComponent<Animator>();
		playerAnimator->CreateAnimation(L"Idle", playerTex
			, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
		playerAnimator->CreateAnimation(L"FrontGiveWater", playerTex
			, Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.1f);
		playerAnimator->PlayAnimation(L"Idle", false);
		playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, plScript);
		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(300.0f, 250.0f));

		///CAT
		Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal);
		//cat->SetActive(true);
		cat->AddComponent<CatScript>();
		//cameraComp->SetTarget(cat);
		graphcis::Texture* catTex = Resources::Find<graphcis::Texture>(L"Cat");
		Animator* catAnimator = cat->AddComponent<Animator>();
		BoxCollider2D* boxCatCollider = cat->AddComponent<BoxCollider2D>();
		boxCatCollider->SetOffset(Vector2(-50.0f, -50.0f));

		catAnimator->CreateAnimationByFolder(L"MushroomIdle", L"..\\Resources\\Mushroom", Vector2::Zero, 0.1f);
		catAnimator->PlayAnimation(L"MushroomIdle", true);
		cat->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
		cat->GetComponent<Transform>()->SetScale(Vector2(1.0f, 1.0f));

		// 게임 오브젝트 생성후에 레이어와 게임오브젝트들의 init함수를 호출
		Scene::Initialize();

	}
	void PlayScene::Update() {
		Scene::Update();

	}
	void PlayScene::LateUpdate() {
		Scene::LateUpdate();
		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		//wchar_t str[50] = L"Play Scene";
		//TextOut(hdc, 0, 0, str, 10);
	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}