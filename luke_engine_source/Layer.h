#pragma once
#include "Entity.h"
#include "CommonInclude.h"
#include "GameObject.h"
namespace luke
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		void AddGameObject(GameObject* gameObject);
	private:
		//eLayerType mType;
		std::vector<GameObject*> mGameObjects;
	};
	typedef std::vector<GameObject*>::iterator GameObjectIter;
}