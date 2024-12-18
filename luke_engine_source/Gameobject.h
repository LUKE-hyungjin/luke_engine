#pragma once
#include "Commoninclude.h"
#include "Input.h"
namespace luke {
	class GameObject
	{
	public:
		GameObject();
		~GameObject();
		void Update();
		void LastUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y) {
			mX = x;
			mY = y;
		}
		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }


	private:
		float mX;
		float mY;

	};
}

