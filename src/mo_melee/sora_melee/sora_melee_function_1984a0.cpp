#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_1984A0(const u32* p)
{
    return (s32)(((p[2] >> 25) & 0xF) << 28) >> 29;
}
}
