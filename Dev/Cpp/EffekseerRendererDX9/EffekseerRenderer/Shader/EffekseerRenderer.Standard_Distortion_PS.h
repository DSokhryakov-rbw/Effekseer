#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//   fxc /Zpc /Tps_3_0 /EPS /D __EFFEKSEER_BUILD_VERSION16__=1 /Fh
//    Shader/EffekseerRenderer.Standard_Distortion_PS.h
//    Shader/standard_renderer_distortion_PS.fx
//
//
// Parameters:
//
//   float4 flipbookParameter;
//   sampler2D g_alphaSampler;
//   sampler2D g_backSampler;
//   sampler2D g_sampler;
//   float4 g_scale;
//   float4 mUVInversedBack;
//
//
// Registers:
//
//   Name              Reg   Size
//   ----------------- ----- ----
//   g_scale           c0       1
//   mUVInversedBack   c1       1
//   flipbookParameter c2       1
//   g_sampler         s0       1
//   g_backSampler     s1       1
//   g_alphaSampler    s2       1
//

    ps_3_0
    def c3, 0, -1, -0, 2
    def c4, 0.5, 1, 0, 0
    dcl_color v0.xyw
    dcl_texcoord v1.xy
    dcl_texcoord1 v2.xyw
    dcl_texcoord2 v3.xyw
    dcl_texcoord3 v4.xyw
    dcl_texcoord4 v5.xy
    dcl_texcoord5 v6.x
    dcl_texcoord6 v7.xy
    dcl_texcoord7 v8.x
    dcl_2d s0
    dcl_2d s1
    dcl_2d s2
    texld r0, v1, s0
    mul r0.z, r0.w, v0.w
    mov r1.xy, c3
    if_lt -c2.x, r1.x
      texld r2, v7, s0
      add r0.w, r1.y, c2.y
      mad r1.xyz, r2.xyww, v0.xyww, -r0
      mad r1.xyz, v6.x, r1, r0
      cmp r0.xyz, -r0_abs.w, r1, r0
    endif
    texld r1, v5, s2
    mul r0.w, r0.z, r1.w
    mad r0.z, r0.z, -r1.w, v8.x
    cmp r1, r0.z, c3.y, c3.z
    texkill r1
    cmp r1, -r0_abs.w, c3.y, c3.z
    texkill r1
    rcp r0.z, v2.w
    mul r1.xy, r0.z, v2
    rcp r0.z, v3.w
    rcp r1.z, v4.w
    mad r0.xy, r0, c3.w, c3.y
    mul r0.xy, r0, v0
    mul r0.xy, r0, c0.x
    mad r1.zw, v4.xyxy, r1.z, -r1.xyxy
    mad r1.zw, r1, r0.x, r1.xyxy
    mad r0.xz, v3.xyyw, r0.z, -r1.xyyw
    mad r0.xy, r0.xzzw, r0.y, r1.zwzw
    add r0.xy, r0, -c3.y
    mul r0.x, r0.x, c4.x
    mad r0.y, r0.y, -c4.x, c4.y
    mad r0.z, c1.y, r0.y, c1.x
    texld r1, r0.xzzw, s1
    mov oC0.xyz, r1
    mov oC0.w, r0.w

// approximately 37 instruction slots used (4 texture, 33 arithmetic)
#endif

const BYTE g_ps30_PS[] =
{
      0,   3, 255, 255, 254, 255, 
     90,   0,  67,  84,  65,  66, 
     28,   0,   0,   0,  51,   1, 
      0,   0,   0,   3, 255, 255, 
      6,   0,   0,   0,  28,   0, 
      0,   0,  16,   1,   0,   0, 
     44,   1,   0,   0, 148,   0, 
      0,   0,   2,   0,   2,   0, 
      1,   0,   0,   0, 168,   0, 
      0,   0,   0,   0,   0,   0, 
    184,   0,   0,   0,   3,   0, 
      2,   0,   1,   0,  10,   0, 
    200,   0,   0,   0,   0,   0, 
      0,   0, 216,   0,   0,   0, 
      3,   0,   1,   0,   1,   0, 
      6,   0, 232,   0,   0,   0, 
      0,   0,   0,   0, 248,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   2,   0,   4,   1, 
      0,   0,   0,   0,   0,   0, 
     20,   1,   0,   0,   2,   0, 
      0,   0,   1,   0,   0,   0, 
    168,   0,   0,   0,   0,   0, 
      0,   0,  28,   1,   0,   0, 
      2,   0,   1,   0,   1,   0, 
      0,   0, 168,   0,   0,   0, 
      0,   0,   0,   0, 102, 108, 
    105, 112,  98, 111, 111, 107, 
     80,  97, 114,  97, 109, 101, 
    116, 101, 114,   0, 171, 171, 
      1,   0,   3,   0,   1,   0, 
      4,   0,   1,   0,   0,   0, 
      0,   0,   0,   0, 103,  95, 
     97, 108, 112, 104,  97,  83, 
     97, 109, 112, 108, 101, 114, 
      0, 171,   4,   0,  12,   0, 
      1,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
    103,  95,  98,  97,  99, 107, 
     83,  97, 109, 112, 108, 101, 
    114,   0, 171, 171,   4,   0, 
     12,   0,   1,   0,   1,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0, 103,  95, 115,  97, 
    109, 112, 108, 101, 114,   0, 
    171, 171,   4,   0,  12,   0, 
      1,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
    103,  95, 115,  99,  97, 108, 
    101,   0, 109,  85,  86,  73, 
    110, 118, 101, 114, 115, 101, 
    100,  66,  97,  99, 107,   0, 
    112, 115,  95,  51,  95,  48, 
      0,  77, 105,  99, 114, 111, 
    115, 111, 102, 116,  32,  40, 
     82,  41,  32,  72,  76,  83, 
     76,  32,  83, 104,  97, 100, 
    101, 114,  32,  67, 111, 109, 
    112, 105, 108, 101, 114,  32, 
     57,  46,  50,  57,  46,  57, 
     53,  50,  46,  51,  49,  49, 
     49,   0,  81,   0,   0,   5, 
      3,   0,  15, 160,   0,   0, 
      0,   0,   0,   0, 128, 191, 
      0,   0,   0, 128,   0,   0, 
      0,  64,  81,   0,   0,   5, 
      4,   0,  15, 160,   0,   0, 
      0,  63,   0,   0, 128,  63, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  31,   0,   0,   2, 
     10,   0,   0, 128,   0,   0, 
     11, 144,  31,   0,   0,   2, 
      5,   0,   0, 128,   1,   0, 
      3, 144,  31,   0,   0,   2, 
      5,   0,   1, 128,   2,   0, 
     11, 144,  31,   0,   0,   2, 
      5,   0,   2, 128,   3,   0, 
     11, 144,  31,   0,   0,   2, 
      5,   0,   3, 128,   4,   0, 
     11, 144,  31,   0,   0,   2, 
      5,   0,   4, 128,   5,   0, 
      3, 144,  31,   0,   0,   2, 
      5,   0,   5, 128,   6,   0, 
      1, 144,  31,   0,   0,   2, 
      5,   0,   6, 128,   7,   0, 
      3, 144,  31,   0,   0,   2, 
      5,   0,   7, 128,   8,   0, 
      1, 144,  31,   0,   0,   2, 
      0,   0,   0, 144,   0,   8, 
     15, 160,  31,   0,   0,   2, 
      0,   0,   0, 144,   1,   8, 
     15, 160,  31,   0,   0,   2, 
      0,   0,   0, 144,   2,   8, 
     15, 160,  66,   0,   0,   3, 
      0,   0,  15, 128,   1,   0, 
    228, 144,   0,   8, 228, 160, 
      5,   0,   0,   3,   0,   0, 
      4, 128,   0,   0, 255, 128, 
      0,   0, 255, 144,   1,   0, 
      0,   2,   1,   0,   3, 128, 
      3,   0, 228, 160,  41,   0, 
      4,   2,   2,   0,   0, 161, 
      1,   0,   0, 128,  66,   0, 
      0,   3,   2,   0,  15, 128, 
      7,   0, 228, 144,   0,   8, 
    228, 160,   2,   0,   0,   3, 
      0,   0,   8, 128,   1,   0, 
     85, 128,   2,   0,  85, 160, 
      4,   0,   0,   4,   1,   0, 
      7, 128,   2,   0, 244, 128, 
      0,   0, 244, 144,   0,   0, 
    228, 129,   4,   0,   0,   4, 
      1,   0,   7, 128,   6,   0, 
      0, 144,   1,   0, 228, 128, 
      0,   0, 228, 128,  88,   0, 
      0,   4,   0,   0,   7, 128, 
      0,   0, 255, 140,   1,   0, 
    228, 128,   0,   0, 228, 128, 
     43,   0,   0,   0,  66,   0, 
      0,   3,   1,   0,  15, 128, 
      5,   0, 228, 144,   2,   8, 
    228, 160,   5,   0,   0,   3, 
      0,   0,   8, 128,   0,   0, 
    170, 128,   1,   0, 255, 128, 
      4,   0,   0,   4,   0,   0, 
      4, 128,   0,   0, 170, 128, 
      1,   0, 255, 129,   8,   0, 
      0, 144,  88,   0,   0,   4, 
      1,   0,  15, 128,   0,   0, 
    170, 128,   3,   0,  85, 160, 
      3,   0, 170, 160,  65,   0, 
      0,   1,   1,   0,  15, 128, 
     88,   0,   0,   4,   1,   0, 
     15, 128,   0,   0, 255, 140, 
      3,   0,  85, 160,   3,   0, 
    170, 160,  65,   0,   0,   1, 
      1,   0,  15, 128,   6,   0, 
      0,   2,   0,   0,   4, 128, 
      2,   0, 255, 144,   5,   0, 
      0,   3,   1,   0,   3, 128, 
      0,   0, 170, 128,   2,   0, 
    228, 144,   6,   0,   0,   2, 
      0,   0,   4, 128,   3,   0, 
    255, 144,   6,   0,   0,   2, 
      1,   0,   4, 128,   4,   0, 
    255, 144,   4,   0,   0,   4, 
      0,   0,   3, 128,   0,   0, 
    228, 128,   3,   0, 255, 160, 
      3,   0,  85, 160,   5,   0, 
      0,   3,   0,   0,   3, 128, 
      0,   0, 228, 128,   0,   0, 
    228, 144,   5,   0,   0,   3, 
      0,   0,   3, 128,   0,   0, 
    228, 128,   0,   0,   0, 160, 
      4,   0,   0,   4,   1,   0, 
     12, 128,   4,   0,  68, 144, 
      1,   0, 170, 128,   1,   0, 
     68, 129,   4,   0,   0,   4, 
      1,   0,  12, 128,   1,   0, 
    228, 128,   0,   0,   0, 128, 
      1,   0,  68, 128,   4,   0, 
      0,   4,   0,   0,   5, 128, 
      3,   0, 212, 144,   0,   0, 
    170, 128,   1,   0, 212, 129, 
      4,   0,   0,   4,   0,   0, 
      3, 128,   0,   0, 232, 128, 
      0,   0,  85, 128,   1,   0, 
    238, 128,   2,   0,   0,   3, 
      0,   0,   3, 128,   0,   0, 
    228, 128,   3,   0,  85, 161, 
      5,   0,   0,   3,   0,   0, 
      1, 128,   0,   0,   0, 128, 
      4,   0,   0, 160,   4,   0, 
      0,   4,   0,   0,   2, 128, 
      0,   0,  85, 128,   4,   0, 
      0, 161,   4,   0,  85, 160, 
      4,   0,   0,   4,   0,   0, 
      4, 128,   1,   0,  85, 160, 
      0,   0,  85, 128,   1,   0, 
      0, 160,  66,   0,   0,   3, 
      1,   0,  15, 128,   0,   0, 
    232, 128,   1,   8, 228, 160, 
      1,   0,   0,   2,   0,   8, 
      7, 128,   1,   0, 228, 128, 
      1,   0,   0,   2,   0,   8, 
      8, 128,   0,   0, 255, 128, 
    255, 255,   0,   0
};
