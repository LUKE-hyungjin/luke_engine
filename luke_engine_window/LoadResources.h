#pragma once
#pragma once
#include "..\\luke_engine_source\\Resources.h"
#include "..\\luke_engine_source\\Texture.h"
namespace luke
{
	//void LoadResources()
	//{
	//	Resources::Load<graphcis::Texture>(L"BG", L"D:\\dev\\luke_engine\\Resources\\CloudOcean.png");
	//}
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\ChickenAlpha.bmp");
		Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\Player.bmp");
		Resources::Load<graphics::Texture>(L"SpringFloor", L"..\\Resources\\SpringFloor.bmp");
	}
}
// 카메라 
// 크기 조정하는거 
// 스크립트
// 이미지 자르기 -> 애니메이션때 진행
// 애니메이션 (회전) -> 타일맵 -> 충돌 -> UI -> 사운드
