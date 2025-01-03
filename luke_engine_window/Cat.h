#pragma once
#include "..\\luke_engine_source\\GameObject.h"

namespace luke
{
	class Cat : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;
	private:
	};
}