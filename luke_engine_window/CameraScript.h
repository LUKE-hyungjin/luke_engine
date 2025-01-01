#pragma once
#include "..\\luke_engine_source\\Script.h"
#include "..\\luke_engine_source\\Transform.h"
namespace luke
{
	class CameraScript : public Script
	{
	public:
		CameraScript();
		~CameraScript();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
	};
}