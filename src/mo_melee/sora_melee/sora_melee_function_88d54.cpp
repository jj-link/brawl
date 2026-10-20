#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" {
void *fn_27_88D54(void *r3, s32 r4)
{
    s32 idx = (*(s32 *)((u8 *)r3 + 8) >> 26) + r4;
    if (idx >= 24) {
        idx -= 24;
    }
    return (u8 *)r3 + (idx << 2) + 12;
}
}
