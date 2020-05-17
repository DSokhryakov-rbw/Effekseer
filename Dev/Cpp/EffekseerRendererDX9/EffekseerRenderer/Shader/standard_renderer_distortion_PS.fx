#define SamplerState sampler2D
// 1.6
#ifdef __EFFEKSEER_BUILD_VERSION16__
#include "FlipbookInterpolationUtils_PS.fx"
#endif


Texture2D	g_texture		: register( t0 );
sampler2D	g_sampler		: register( s0 );

Texture2D	g_backTexture		: register( t1 );
SamplerState	g_backSampler		: register( s1 );

#ifdef __EFFEKSEER_BUILD_VERSION16__
Texture2D g_alphaTexture        : register(t2);
SamplerState g_alphaSampler     : register(s2);
#endif

#ifdef __EFFEKSEER_BUILD_VERSION16__
cbuffer PS_ConstanBuffer : register(b0)
{
    float4 g_scale;
    float4 mUVInversedBack;
    float4 flipbookParameter; // x:enable, y:interpolationType
};
#else
float4		g_scale			: register(c0);
float4 mUVInversedBack		: register(c1);
#endif

struct PS_Input
{
	float4 Color		: COLOR;
	float2 UV		: TEXCOORD0;

	float4 Pos		: TEXCOORD1;
	float4 PosU		: TEXCOORD2;
	float4 PosR		: TEXCOORD3;

#ifdef __EFFEKSEER_BUILD_VERSION16__
    float2 AlphaUV  : TEXCOORD4;
    float FlipbookRate : TEXCOORD5;
    float2 FlipbookNextIndexUV : TEXCOORD6;
    float AlphaThreshold : TEXCOORD7;
#endif
};


float4 PS( const PS_Input Input ) : COLOR
{
	float4 Output = tex2D(g_sampler, Input.UV);
	Output.a = Output.a * Input.Color.a;

#ifdef __EFFEKSEER_BUILD_VERSION16__
	ApplyFlipbook(Output, g_texture, g_sampler, flipbookParameter, Input.Color, Input.FlipbookNextIndexUV, Input.FlipbookRate);

    Output.a *= tex2D(g_alphaSampler, Input.AlphaUV).a;
    
    // alpha threshold
    if(Output.a <= Input.AlphaThreshold)
    {
        discard;
    }
#endif

	if(Output.a == 0.0f) discard;

	float2 pos = Input.Pos.xy / Input.Pos.w;
	float2 posU = Input.PosU.xy / Input.PosU.w;
	float2 posR = Input.PosR.xy / Input.PosR.w;

	float xscale = (Output.x * 2.0 - 1.0) * Input.Color.x * g_scale.x;
	float yscale = (Output.y * 2.0 - 1.0) * Input.Color.y * g_scale.x;

	float2 uv = pos + (posR - pos) * xscale + (posU - pos) * yscale;

	uv.x = (uv.x + 1.0) * 0.5;
	uv.y = 1.0 - (uv.y + 1.0) * 0.5;

	uv.y = mUVInversedBack.x + mUVInversedBack.y * uv.y;

	float3 color = tex2D(g_backSampler, uv);
	Output.xyz = color;

	return Output;
}
