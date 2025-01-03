#pragma once
#include "Camera.h"
#include "GraphicDevice_DX11.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "ConstantBuffer.h"
using namespace luke::math;
using namespace luke::graphics;

namespace luke::renderer
{
	extern Camera* mainCamera;

	extern std::vector<graphics::Vertex> vertexes;
	extern std::vector<UINT> indices;

	extern graphics::VertexBuffer vertexBuffer;
	extern graphics::IndexBuffer indexBuffer;
	extern graphics::ConstantBuffer constantBuffers[(UINT)eCBType::End];
	extern ID3D11Buffer* constantBuffer;
	extern ID3D11InputLayout* inputLayouts;

	void Initialize();
	void Release();
}