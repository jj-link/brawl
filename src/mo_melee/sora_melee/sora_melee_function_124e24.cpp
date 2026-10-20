#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
char* fn_27_124E24(char* p, s32 n)
{
    s32 i = (*(s32*)(p + 8) >> 26) + n;
    if (i >= 0x10) {
        i -= 0x10;
    }
    return p + i * 0x18 + 0xC;
}
}
