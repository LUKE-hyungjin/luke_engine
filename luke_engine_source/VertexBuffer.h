#pragma once
#include "GraphicDevice_DX11.h"
namespace luke::graphics
{
	class VertexBuffer : public GpuBuffer
	{
	public:
		VertexBuffer();
		~VertexBuffer();
		bool Create(const std::vector<Vertex>& vertexes);
		void Bind();
	private:
	};
}