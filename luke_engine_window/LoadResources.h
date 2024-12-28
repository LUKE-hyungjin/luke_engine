#pragma once
#pragma once
#include "..\\luke_engine_source\\Resources.h"
#include "..\\luke_engine_source\\Texture.h"
namespace luke
{
	void LoadResources()
	{
		Resources::Load<graphcis::Texture>(L"BG", L"D:\\dev\\luke_engine\\Resources\\CloudOcean.png");
	}
}