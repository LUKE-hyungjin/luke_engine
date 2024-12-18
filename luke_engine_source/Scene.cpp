#include "Scene.h"

namespace luke
{
	Scene::Scene()
		:mGameObject{}
	{

	}
	Scene::~Scene()
	{

	}
	void Scene::Initialize() {

	}
	void Scene::Update() {
		for (GameObject* gmaeObj : mGameObject) {
			gmaeObj->Update();
		}
	}
	void Scene::LateUpdate() {
		for (GameObject* gmaeObj : mGameObject) {
			gmaeObj->LastUpdate();
		}
	}
	void Scene::Render(HDC hdc) {
		for (GameObject* gmaeObj : mGameObject) {
			gmaeObj->Render(hdc);
		}
	}
	void Scene::AddGameObject(GameObject* gameObject)
	{
		mGameObject.push_back(gameObject);
	}
}