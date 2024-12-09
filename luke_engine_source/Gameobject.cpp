#include "GameObject.h"
#include "Input.h"

namespace luke {

		GameObject::GameObject(): mX(0.0f), mY(0.0f) {

		}
		GameObject::~GameObject() {

		}
		void GameObject::Update() {
			if (Input::GetKey(eKeyCode::A)) {
				mX -= 0.1f;
			}
			if (Input::GetKey(eKeyCode::D)) {
				mX += 0.1f;
			}
			if (Input::GetKey(eKeyCode::W)) {
				mY -= 0.1f;
			}
			if (Input::GetKey(eKeyCode::S)) {
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

