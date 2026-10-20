#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" u8* fn_27_1B04E4(u8* p, s32 idx)
{
    s32 a = ((s32*)p)[2] >> 26;
    if (a + idx >= 0x14) {
        idx = a + idx - 0x14;
    } else {
        idx = a + idx;
    }
    return p + idx * 0x68 + 0xc;
}
