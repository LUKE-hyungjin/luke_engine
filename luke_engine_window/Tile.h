#pragma once
#include "..\\luke_engine_source\\GameObject.h"
namespace luke
{
	class Tile : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void SetIndexPosition(int x, int y);
	private:
	};
}