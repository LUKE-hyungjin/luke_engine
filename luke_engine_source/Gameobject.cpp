#include "GameObject.h"

namespace luke {

		GameObject::GameObject(): mX(0.0f), mY(0.0f) {

		}
		GameObject::~GameObject() {

		}
		void GameObject::Update() {
			if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
				mX -= 0.1f;
			}
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
				mX += 0.1f;
			}
			if (GetAsyncKeyState(VK_UP) & 0x8000) {
				mY -= 0.1f;
			}
			if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
				mY += 0.1f;
			}
		}
		void GameObject::LastUpdate() {

		}
		void GameObject::Render(HDC mHdc) {
			HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
			HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush);
			Rectangle(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		}


}

