#pragma once
#include "GraphicDevice_DX11.h"
namespace luke::graphics
{
	class IndexBuffer : public GpuBuffer
	{
	public:
		IndexBuffer();
		~IndexBuffer();
		bool Create(const std::vector<UINT>& indices);
		void Bind();
	private:
	};
}