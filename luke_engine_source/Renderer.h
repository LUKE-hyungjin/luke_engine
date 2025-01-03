#pragma once
#include "Camera.h"
#include "GraphicDevice_DX11.h"

namespace luke::renderer
{
	extern Camera* mainCamera;
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
	};

	extern Vertex vertexes[3];
	extern std::vector<UINT> indices;
	extern ID3D11Buffer* vertexBuffer;
	extern ID3D11Buffer* indexBuffer;
	extern ID3DBlob* vsBlob;
	extern ID3D11VertexShader* vsShader;
	extern ID3DBlob* psBlob;
	extern ID3D11PixelShader* psShader;
	extern ID3D11InputLayout* inputLayouts;

	void Initialize();
	void Release();
}