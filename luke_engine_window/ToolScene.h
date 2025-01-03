#pragma once
#include "..\\luke_engine_source\\Scene.h"
#include "Tile.h"
namespace luke
{
	class ToolScene : public Scene
	{
	public:
		ToolScene();
		~ToolScene();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;
		void OnEnter() override;
		void OnExit()  override;
		void Save();
		void Load();
	private:
		void renderGreed();
		void createTileObject();

	private:
		std::vector<Tile*> mTiles;

	};
}
LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);