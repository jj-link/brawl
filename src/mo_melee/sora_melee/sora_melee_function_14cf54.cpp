#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" {
void fn_27_14CF54(u8* p, s32 idx, s32 val)
{
    *(s32*)(p + idx * 4 + 0xb8) += val;
}
}
