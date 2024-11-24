Texture2D baseColorTexture : register(t0);
SamplerState baseColorSampler : register(s0);

struct VSOutput
{
    float4 position : SV_POSITION;
    float3 color : COLOR;
};

float4 main(VSOutput vsOutput) : SV_TARGET
{
    return float4(vsOutput.color, 1.0);
}
