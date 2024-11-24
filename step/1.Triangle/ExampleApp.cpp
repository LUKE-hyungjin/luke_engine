#include "ExampleApp.h"

#include <tuple>
#include <vector>

namespace luke
{

    using namespace std;

    auto MakeTriangle()
    {
        vector<Vector3> positions;
        vector<Vector3> colors;
        vector<Vector3> normals;
        vector<Vector2> texcoords;

        const float scale = 1.0f;

        // 삼각형의 세 점 정의
        positions.push_back(Vector3(-1.0f, -1.0f, 0.0f) * scale); // 왼쪽 아래
        positions.push_back(Vector3(1.0f, -1.0f, 0.0f) * scale);  // 오른쪽 아래
        positions.push_back(Vector3(0.0f, 1.0f, 0.0f) * scale);   // 위쪽 중앙

        // RGB 색상 설정
        colors.push_back(Vector3(1.0f, 0.0f, 0.0f)); // 빨간색
        colors.push_back(Vector3(0.0f, 1.0f, 0.0f)); // 초록색
        colors.push_back(Vector3(0.0f, 0.0f, 1.0f)); // 파란색

        // 법선 벡터
        normals.push_back(Vector3(0.0f, 0.0f, -1.0f));
        normals.push_back(Vector3(0.0f, 0.0f, -1.0f));
        normals.push_back(Vector3(0.0f, 0.0f, -1.0f));

        // 텍스처 좌표
        texcoords.push_back(Vector2(0.0f, 1.0f));
        texcoords.push_back(Vector2(1.0f, 1.0f));
        texcoords.push_back(Vector2(0.5f, 0.0f));

        vector<Vertex> vertices;
        for (size_t i = 0; i < positions.size(); i++)
        {
            Vertex v;
            v.position = positions[i];
            v.color = colors[i];
            v.texcoord = texcoords[i];
            vertices.push_back(v);
        }

        // 삼각형을 그리기 위한 인덱스
        vector<uint16_t> indices = {0, 1, 2};

        return tuple{vertices, indices};
    }

    ExampleApp::ExampleApp()
        : AppBase(), m_indexCount(0), m_pixelShaderConstantBufferData() {}

    bool ExampleApp::Initialize()
    {

        if (!AppBase::Initialize())
            return false;

        // Texture 만들기
        // https://opengameart.org/content/3-crate-textures-w-bump-normal
        // https://learnopengl.com/Getting-started/Textures
        // AppBase::CreateTexture("crate2_diffuse.png", m_texture,
        //    m_textureResourceView);
        // AppBase::CreateTexture("wall.jpg", m_texture2,
        //    m_textureResourceView2);

        // Texture sampler 만들기
        // D3D11_SAMPLER_DESC sampDesc;
        // ZeroMemory(&sampDesc, sizeof(sampDesc));
        // sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
        // sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
        // sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
        // sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
        // sampDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
        // sampDesc.MinLOD = 0;
        // sampDesc.MaxLOD = D3D11_FLOAT32_MAX;

        //// Create the Sample State
        // m_device->CreateSamplerState(&sampDesc, m_samplerState.GetAddressOf());

        // Geometry 정의
        auto [vertices, indices] = MakeTriangle();

        // 버텍스 버퍼 만들기
        AppBase::CreateVertexBuffer(vertices, m_vertexBuffer);

        // 인덱스 버퍼 만들기
        m_indexCount = UINT(indices.size());

        AppBase::CreateIndexBuffer(indices, m_indexBuffer);

        // ConstantBuffer 만들기
        m_constantBufferData.model = Matrix();
        m_constantBufferData.view = Matrix();
        m_constantBufferData.projection = Matrix();

        AppBase::CreateConstantBuffer(m_constantBufferData, m_constantBuffer);

        AppBase::CreateConstantBuffer(m_pixelShaderConstantBufferData,
                                      m_pixelShaderConstantBuffer);

        // 쉐이더 만들기

        // Input-layout objects describe how vertex buffer data is streamed into the
        // IA(Input-Assembler) pipeline stage.
        // https://learn.microsoft.com/en-us/windows/win32/api/d3d11/nf-d3d11-id3d11devicecontext-iasetinputlayout

        // Input-Assembler Stage
        // The purpose of the input-assembler stage is to read primitive data
        // (points, lines and/or triangles) from user-filled buffers and assemble
        // the data into primitives that will be used by the other pipeline stages.
        // https://learn.microsoft.com/en-us/windows/win32/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage

        // D3D11_INPUT_ELEMENT_DESC structure(d3d11.h)
        // https://learn.microsoft.com/en-us/windows/win32/api/d3d11/ns-d3d11-d3d11_input_element_desc

        // Semantics
        // https://learn.microsoft.com/en-us/windows/win32/direct3dhlsl/dx-graphics-hlsl-semantics

        vector<D3D11_INPUT_ELEMENT_DESC> inputElements = {
            {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,
             D3D11_INPUT_PER_VERTEX_DATA, 0},
            {"COLOR", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 4 * 3,
             D3D11_INPUT_PER_VERTEX_DATA, 0},
        };

        AppBase::CreateVertexShaderAndInputLayout(
            L"VertexShader.hlsl", inputElements, m_colorVertexShader,
            m_colorInputLayout);

        AppBase::CreatePixelShader(L"PixelShader.hlsl", m_colorPixelShader);

        return true;
    }

    void ExampleApp::Update(float dt)
    {

        using namespace DirectX;

        // 모델의 변환
        m_constantBufferData.model =
            Matrix::CreateScale(1.5f) *
            Matrix::CreateTranslation(Vector3(0.0f, 0.0f, 1.0f));
        m_constantBufferData.model = m_constantBufferData.model.Transpose();

        // 시점 변환
        // m_constantBufferData.view = XMMatrixLookAtLH(m_viewEye, m_viewFocus,
        // m_viewUp);
        m_constantBufferData.view =
            XMMatrixLookToLH(m_viewEyePos, m_viewEyeDir, m_viewUp);
        m_constantBufferData.view = m_constantBufferData.view.Transpose();

        // 프로젝션
        // m_aspect = AppBase::GetAspectRatio(); // <- GUI에서 조절
        if (m_usePerspectiveProjection)
        {
            m_constantBufferData.projection = XMMatrixPerspectiveFovLH(
                XMConvertToRadians(m_projFovAngleY), m_aspect, m_nearZ, m_farZ);
        }
        else
        {
            m_constantBufferData.projection = XMMatrixOrthographicOffCenterLH(
                -m_aspect, m_aspect, -1.0f, 1.0f, m_nearZ, m_farZ);
        }
        m_constantBufferData.projection =
            m_constantBufferData.projection.Transpose();

        // Constant를 CPU에서 GPU로 복사
        AppBase::UpdateBuffer(m_constantBufferData, m_constantBuffer);

        AppBase::UpdateBuffer(m_pixelShaderConstantBufferData,
                              m_pixelShaderConstantBuffer);

        vector<Vertex> vertices;
        for (int i = 0; i < 3; i++)
        {
            Vertex v;
            v.position = m_trianglePositions[i];
            v.color = m_triangleColors[i];
            v.texcoord = Vector2(0.0f, 0.0f); // 텍스처 좌표는 사용하지 않음
            vertices.push_back(v);
        }

        // 버텍스 버퍼 업데이트
        D3D11_MAPPED_SUBRESOURCE ms;
        m_context->Map(m_vertexBuffer.Get(), NULL, D3D11_MAP_WRITE_DISCARD, NULL, &ms);
        memcpy(ms.pData, vertices.data(), vertices.size() * sizeof(Vertex));
        m_context->Unmap(m_vertexBuffer.Get(), NULL);
    }

    void ExampleApp::Render()
    {

        // RS: Rasterizer stage
        // OM: Output-Merger stage
        // VS: Vertex Shader
        // PS: Pixel Shader
        // IA: Input-Assembler stage

        m_context->RSSetViewports(1, &m_screenViewport);

        float clearColor[4] = {0.0f, 0.0f, 0.0f, 1.0f};
        m_context->ClearRenderTargetView(m_renderTargetView.Get(), clearColor);
        m_context->ClearDepthStencilView(m_depthStencilView.Get(),
                                         D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL,
                                         1.0f, 0);

        // 비교: Depth Buffer를 사용하지 않는 경우
        // m_context->OMSetRenderTargets(1, m_renderTargetView.GetAddressOf(),
        // nullptr);
        m_context->OMSetRenderTargets(1, m_renderTargetView.GetAddressOf(),
                                      m_depthStencilView.Get());
        m_context->OMSetDepthStencilState(m_depthStencilState.Get(), 0);

        // 어떤 쉐이더를 사용할지 설정
        m_context->VSSetShader(m_colorVertexShader.Get(), 0, 0);

        /* 경우에 따라서는 포인터의 배열을 넣어줄 수도 있습니다.
        ID3D11Buffer *pptr[1] = {
            m_constantBuffer.Get(),
        };
        m_context->VSSetConstantBuffers(0, 1, pptr); */

        m_context->VSSetConstantBuffers(0, 1, m_constantBuffer.GetAddressOf());

        // ID3D11ShaderResourceView* pixelResources[2] = { m_textureResourceView.Get(),
        //                                                m_textureResourceView2.Get() };
        // m_context->PSSetShaderResources(0, 2, pixelResources);
        // m_context->PSSetSamplers(0, 1, m_samplerState.GetAddressOf());

        m_context->PSSetConstantBuffers(0, 1,
                                        m_pixelShaderConstantBuffer.GetAddressOf());
        m_context->PSSetShader(m_colorPixelShader.Get(), 0, 0);
        m_context->RSSetState(m_rasterizerSate.Get());

        // 버텍스/인덱스 버퍼 설정
        UINT stride = sizeof(Vertex);
        UINT offset = 0;
        m_context->IASetInputLayout(m_colorInputLayout.Get());
        m_context->IASetVertexBuffers(0, 1, m_vertexBuffer.GetAddressOf(), &stride,
                                      &offset);
        m_context->IASetIndexBuffer(m_indexBuffer.Get(), DXGI_FORMAT_R16_UINT, 0);
        m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
        m_context->DrawIndexed(m_indexCount, 0, 0);
    }

    void ExampleApp::UpdateGUI()
    {
        // ImGui::SliderFloat2("splitUV", &.x, -2.0f, 2.0f);

        // 각 꼭지점의 위치 조절
        ImGui::Text(u8"삼각형 꼭지점 위치");
        ImGui::SliderFloat3("Vertex 1", &m_trianglePositions[0].x, -2.0f, 2.0f);
        ImGui::SliderFloat3("Vertex 2", &m_trianglePositions[1].x, -2.0f, 2.0f);
        ImGui::SliderFloat3("Vertex 3", &m_trianglePositions[2].x, -2.0f, 2.0f);

        // 각 꼭지점의 색상 조절
        ImGui::Text(u8"삼각형 꼭지점 색상");
        ImGui::ColorEdit3("Color 1", &m_triangleColors[0].x);
        ImGui::ColorEdit3("Color 2", &m_triangleColors[1].x);
        ImGui::ColorEdit3("Color 3", &m_triangleColors[2].x);
    }

} // namespace hlab
