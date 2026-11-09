#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern void* g_GameGlobal;

extern "C" s32 fn_800E8CFC(void* unused, s32 arg1) {
    u8* base = *(u8**)((u8*)g_GameGlobal + 0x18);
    u8* p = base + arg1 * 0x2AC;
    u32 a = *(u32*)(p + 0x1E8);
    u32 b = *(u32*)(p + 0x1EC);
    s32 r;

    if (a > 100) {
        a = 100;
    }
    if (a % 5 == 0) {
        if (a == 0) {
            r = 1;
        } else {
            r = a / 5;
        }
    } else {
        r = a / 5 + 1;
    }

    if (b > 100) {
        b = 100;
    }
    if (b % 5 == 0) {
        if (b == 0) {
            r = r + 1;
        } else {
            r = r + b / 5;
        }
    } else {
        r = r + b / 5 + 1;
    }
    return r + 4;
}
