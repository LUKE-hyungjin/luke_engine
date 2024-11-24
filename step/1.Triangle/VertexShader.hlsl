struct VSInput
{
    float4 position : POSITION;
    float3 color : COLOR0;
};

struct VSOutput
{
    float4 position : SV_POSITION;
    float3 color : COLOR;
};

VSOutput main(VSInput vsInput)
{
    VSOutput vsOutput;

    vsOutput.position = vsInput.position;
    vsOutput.color = vsInput.color;

    return vsOutput;
}
