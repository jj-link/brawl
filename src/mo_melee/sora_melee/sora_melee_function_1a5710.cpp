#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_1A5710(void* self)
{
    u32 v = *(u32*)((char*)self + 8);
    return (s32)((v << 4) & 0xF8000000) >> 28;
}
}
