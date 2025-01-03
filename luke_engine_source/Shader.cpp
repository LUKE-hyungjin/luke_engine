#include "Shader.h"

namespace luke::graphics
{
	Shader::Shader()
		: Resource(enums::eResourceType::Shader)
	{
	}
	Shader::~Shader()
	{
	}
	HRESULT Shader::Save(const std::wstring& path)
	{
		return E_NOTIMPL;
	}
	HRESULT Shader::Load(const std::wstring& path)
	{
		size_t fineNameBeginOffset = path.rfind(L"\\") + 1;
		size_t fineNameEndOffset = path.length() - fineNameBeginOffset;
		const std::wstring fileName(path.substr(fineNameBeginOffset, fineNameEndOffset));
		if (!Create(eShaderStage::VS, fileName))
			return S_FALSE;
		if (!Create(eShaderStage::PS, fileName))
			return S_FALSE;
		return S_OK;
	}
	bool Shader::Create(const eShaderStage stage, const std::wstring& fileName)
	{
		if (stage == eShaderStage::VS)
			CreateVertexShader(fileName);
		if (stage == eShaderStage::PS)
			CreatePixelShader(fileName);
		return true;
	}
	bool Shader::CreateVertexShader(const std::wstring& fileName)
	{
		if (!GetDevice()->CreateVertexShader(fileName, mVSBlob.GetAddressOf(), mVS.GetAddressOf()))
			return false;
		return true;
	}
	bool Shader::CreatePixelShader(const std::wstring& fileName)
	{
		if (!GetDevice()->CreatePixelShader(fileName, mPSBlob.GetAddressOf(), mPS.GetAddressOf()))
			return false;
		return true;
	}

	void Shader::Bind()
	{
		if (mVS)
			GetDevice()->BindVS(mVS.Get());
		if (mPS)
			GetDevice()->BindPS(mPS.Get());
	}
}