#pragma once
#include "Component.h"
#include "GameObject.h"
#include "Layer.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Transform.h"


namespace luke::object
{
	template <typename T>
	static T* Instantiate(luke::enums::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);
		return gameObject;
	}
	template <typename T>
	static T* Instantiate(luke::enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);
		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);
		return gameObject;
	}
}