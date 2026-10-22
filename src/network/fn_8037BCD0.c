#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern void *memcpy(void *dst, const void *src, u32 n);

s32 fn_8037BCD0(u8 *arg0, void *arg1, s32 arg2)
{
    if (arg2 == 0) {
        return 1;
    }
    if (*(s32 *)(arg0 + 0xC) < arg2) {
        return 0;
    }
    memcpy(arg1, *(u8 **)(arg0 + 4) + *(s32 *)(arg0 + 0x10), arg2);
    *(s32 *)(arg0 + 0x10) += arg2;
    return 1;
}
