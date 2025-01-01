#pragma once
#include "..\\luke_engine_source\GameObject.h"
namespace luke
{
	class Floor : public GameObject
	{
	public:
		Floor();
		~Floor();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
	};
}