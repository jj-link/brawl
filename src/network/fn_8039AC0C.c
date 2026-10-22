#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

s32 fn_8039AC0C(void *arg0, s32 unused, s32 arg2, s32 arg3) {
    u32 flags = *(u32 *)((u8 *)arg0 + 4);
    u8 idx;
    u8 *slot;

    if ((flags & 0x100) == 0 || (flags & 0x200) != 0) {
        return -7;
    }
    if ((flags & 1) == 0) {
        return -4;
    }
    idx = ((u8 *)arg0)[0xC8];
    if (idx >= 8) {
        return -6;
    }
    slot = (u8 *)arg0 + (idx << 3);
    *(s32 *)(slot + 0x8C) = arg3;
    *(s32 *)(slot + 0x88) = arg2;
    ((u8 *)arg0)[0xC8] = ((u8 *)arg0)[0xC8] + 1;
    return 0;
}
