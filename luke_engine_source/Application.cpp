#include "Application.h"

namespace luke {
	Application::Application() : mHwnd(nullptr), mHdc(nullptr) {

	}
	Application::~Application(){}
	void Application::Initialize(HWND hwnd) {
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);

		mPlayer.SetPosition(0.0f, 0.0f);
	}
	void Application::Run() {
		Update();
		LateUpdate();
		Render();

	}
	void Application::Update() {
		mPlayer.Update();
	}
	void Application::LateUpdate() {

	}
	void Application::Render() {
		mPlayer.Render(mHdc);
	}
}

