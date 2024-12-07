#pragma once
#include "Commoninclude.h"
namespace luke {
	class GameObject
	{
	public:
		GameObject();
		~GameObject();
		void Update();
		void LastUpdate();
		void Render(HDC mHdc);

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

