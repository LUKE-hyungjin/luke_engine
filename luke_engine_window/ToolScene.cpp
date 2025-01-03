#include "ToolScene.h"
#include "Object.h"
#include "Tile.h"
#include "TilemapRenderer.h"
#include "Resources.h"
#include "Texture.h"
#include "Camera.h"
#include "Renderer.h"
#include "Input.h"
#include "CameraScript.h"
namespace luke
{
	ToolScene::ToolScene()
	{
	}
	ToolScene::~ToolScene()
	{
	}
	void ToolScene::Initialize()
	{
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::Particle, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		camera->AddComponent<CameraScript>();
		renderer::mainCamera = cameraComp;
		Scene::Initialize();
	}
	void ToolScene::Update()
	{
		Scene::Update();
	}
	void ToolScene::LateUpdate()
	{
		Scene::LateUpdate();
		if (Input::GetKeyDown(eKeyCode::LButton))
		{
			createTileObject();
		}
		if (Input::GetKeyDown(eKeyCode::S))
		{
			Save();
		}
		if (Input::GetKeyDown(eKeyCode::L))
		{
			Load();
		}
	}
	void ToolScene::Render()
	{
		Scene::Render();
		renderGreed();
	}
	void ToolScene::OnEnter()
	{
		Scene::OnEnter();
	}
	void ToolScene::OnExit()
	{
		Scene::OnExit();
	}
	void ToolScene::Save()
	{
		// open a file name
		OPENFILENAME ofn = {};
		wchar_t szFilePath[256] = {};
		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"Tile\0*.tile\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
		if (false == GetSaveFileName(&ofn))
			return;
		FILE* pFile = nullptr;
		_wfopen_s(&pFile, szFilePath, L"wb");
		for (Tile* tile : mTiles)
		{
			TilemapRenderer* tmr = tile->GetComponent<TilemapRenderer>();
			Transform* tr = tile->GetComponent<Transform>();

			Vector2 sourceIndex = tmr->GetIndex();
			Vector2 position = tr->GetPosition();
			int x = sourceIndex.x;
			fwrite(&x, sizeof(int), 1, pFile);
			int y = sourceIndex.y;
			fwrite(&y, sizeof(int), 1, pFile);
			x = position.x;
			fwrite(&x, sizeof(int), 1, pFile);
			y = position.y;
			fwrite(&y, sizeof(int), 1, pFile);
		}

		fclose(pFile);
	}
	void ToolScene::Load()
	{
		OPENFILENAME ofn = {};
		wchar_t szFilePath[256] = {};
		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"All\0*.*\0Text\0*.TXT\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
		if (false == GetOpenFileName(&ofn))
			return;
		FILE* pFile = nullptr;
		_wfopen_s(&pFile, szFilePath, L"rb");
		while (true)
		{
			int idxX = 0;
			int idxY = 0;
			int posX = 0;
			int posY = 0;
			if (fread(&idxX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&idxY, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posY, sizeof(int), 1, pFile) == NULL)
				break;
			Tile* tile = object::Instantiate<Tile>(eLayerType::Tile);
			TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();
			tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));
			tmr->SetIndex(Vector2(idxX, idxY));
			mTiles.push_back(tile);
		}
		fclose(pFile);
	}
	void ToolScene::renderGreed()
	{
		//for (size_t i = 0; i < 50; i++)
		//{
		//	Vector2 pos = renderer::mainCamera->CaluatePosition
		//	(
		//		Vector2(TilemapRenderer::TileSize.x * i, 0.0f)
		//	);
		//	MoveToEx(hdc, pos.x, 0, NULL);
		//	LineTo(hdc, pos.x, 1000);
		//}
		//for (size_t i = 0; i < 50; i++)
		//{
		//	Vector2 pos = renderer::mainCamera->CaluatePosition
		//	(
		//		Vector2(0.0f, TilemapRenderer::TileSize.y * i)
		//	);
		//	MoveToEx(hdc, 0, pos.y, NULL);
		//	LineTo(hdc, 1000, pos.y);
		//}
	}
	void ToolScene::createTileObject()
	{
		Vector2 pos = Input::GetMousePosition();
		pos = renderer::mainCamera->CaluateTilePosition(pos);
		if (pos.x >= 0.0f && pos.y >= 0.0f)
		{
			int idxX = pos.x / TilemapRenderer::TileSize.x;
			int idxY = pos.y / TilemapRenderer::TileSize.y;
			Tile* tile = object::Instantiate<Tile>(eLayerType::Tile);
			TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();
			tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));
			tmr->SetIndex(TilemapRenderer::SelectedIndex);
			tile->SetIndexPosition(idxX, idxY);
			mTiles.push_back(tile);
		}
		else
		{
			//
		}
	}
}
LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		POINT mousePos = { };
		GetCursorPos(&mousePos);
		ScreenToClient(hWnd, &mousePos);
		luke::math::Vector2 mousePosition;
		mousePosition.x = mousePos.x;
		mousePosition.y = mousePos.y;
		int idxX = mousePosition.x / luke::TilemapRenderer::OriginTileSize.x;
		int idxY = mousePosition.y / luke::TilemapRenderer::OriginTileSize.y;
		luke::TilemapRenderer::SelectedIndex = Vector2(idxX, idxY);
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		BeginPaint(hWnd, &ps);
		
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;

}