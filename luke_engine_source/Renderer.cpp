#include "Renderer.h"
#include "GraphicDevice_DX11.h"
#include "Resources.h"
#include "Shader.h"

namespace luke::renderer
{
	Camera *mainCamera = nullptr;
	std::vector<graphics::Vertex> vertexes = {};
	std::vector<UINT> indices;
	Mesh *mesh = nullptr;
	graphics::ConstantBuffer constantBuffers[(UINT)eCBType::End] = {};
	ID3D11Buffer *constantBuffer = nullptr;
	ID3D11InputLayout *inputLayouts = nullptr;

	void LoadTriangleMesh()
	{
		mesh = new Mesh();
		renderer::vertexes.resize(3);
		renderer::vertexes[0].pos = Vector3(0.0f, 0.5f, 0.0f);
		renderer::vertexes[0].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		renderer::vertexes[1].pos = Vector3(0.5f, -0.5f, 0.0f);
		renderer::vertexes[1].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
		renderer::vertexes[2].pos = Vector3(-0.5f, -0.5f, 0.0f);
		renderer::vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		indices.push_back(0);
		indices.push_back(1);
		indices.push_back(2);

		mesh->CreateVB(vertexes);
		mesh->CreateIB(indices);
	}
	void LoadSquareMesh()
	{
		mesh = new Mesh();
		renderer::vertexes.resize(4);
		renderer::vertexes[0].pos = Vector3(-0.5f, 0.5f, 0.0f);
		renderer::vertexes[0].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		renderer::vertexes[1].pos = Vector3(0.5f, 0.5f, 0.0f);
		renderer::vertexes[1].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
		renderer::vertexes[2].pos = Vector3(0.5f, -0.5f, 0.0f);
		renderer::vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
		renderer::vertexes[3].pos = Vector3(-0.5f, -0.5f, 0.0f);
		renderer::vertexes[3].color = Vector4(1.0f, 1.0f, 0.0f, 1.0f);

		indices.push_back(0);
		indices.push_back(1);
		indices.push_back(2);
		indices.push_back(0);
		indices.push_back(2);
		indices.push_back(3);

		mesh->CreateVB(vertexes);
		mesh->CreateIB(indices);
	}
	void LoadMeshes()
	{
		LoadSquareMesh();
	}
	void LoadShaders()
	{
		luke::Resources::Load<graphics::Shader>(L"TriangleShader", L"..\\Shaders_SOURCE\\Triangle");
	}
	void LoadConstantBuffers()
	{
		constantBuffers[(UINT)eCBType::Transform].Create(eCBType::Transform, sizeof(Vector4));
	}
	void Initialize()
	{
		LoadMeshes();
		LoadShaders();
		LoadConstantBuffers();
	}
	void Release()
	{
		inputLayouts->Release();
		delete mesh;
	}
}