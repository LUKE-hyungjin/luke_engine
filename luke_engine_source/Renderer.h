#pragma once
#include "Camera.h"
#include "GraphicDevice_DX11.h"
#include "Mesh.h"
#include "ConstantBuffer.h"
using namespace luke::math;
using namespace luke::graphics;

namespace luke::renderer
{
	extern Camera* mainCamera;

	extern std::vector<graphics::Vertex> vertexes;
	extern std::vector<UINT> indices;

	extern Mesh* mesh;
	extern graphics::ConstantBuffer constantBuffers[(UINT)eCBType::End];
	extern ID3D11Buffer* constantBuffer;
	extern ID3D11InputLayout* inputLayouts;

	void Initialize();
	void Release();
}