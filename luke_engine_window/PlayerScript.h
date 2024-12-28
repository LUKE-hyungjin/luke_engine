#pragma once
#include "..\\luke_engine_source\Script.h"

namespace luke
{
	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		~PlayerScript();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
	};
}