#pragma force_active on
typedef unsigned int u32;

struct Fn27Src {
    char pad[0x20];
    float a;
    float b;
    float c;
    u32 d;
};

extern "C" void fn_27_302E8(const Fn27Src* src, void* unused, float* outA, float* outB, float* outC, u32* outD)
{
    *outA = src->a;
    *outB = src->b;
    *outC = src->c;
    *outD = src->d;
}
