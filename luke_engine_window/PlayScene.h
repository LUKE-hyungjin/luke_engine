#pragma once
#include "..//luke_engine_source/Scene.h"


namespace luke {
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;
		void OnEnter() override;
		void OnExit()  override;

	private:
		class Player* mPlayer;
	};
}


