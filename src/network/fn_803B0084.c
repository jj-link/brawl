#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern s32 fn_803AF50C(void *, void *, s32, u32);

s32 fn_803B0084(void *arg0, s32 arg1, u32 arg2)
{
    s32 result;

    if (arg2 >= *(u32 *)((u8 *)arg0 + 8)) {
        return 0x10;
    }

    result = fn_803AF50C(arg0, (u8 *)arg0 + 0x15F4, arg1, arg2);
    return result & ((-result | result) >> 31);
}
