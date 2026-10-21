#pragma force_active on
typedef unsigned int u32;
typedef int s32;

s32 fn_803B84E8(void *arg0) {
    if (arg0 == 0) {
        return 10;
    }
    *(u32 *)((char *)arg0 + 0x1C) = 0;
    return 0;
}
