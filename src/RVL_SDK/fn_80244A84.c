#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern void *fn_8022EFF8(s32);
extern void fn_80242908(void *);

u8 fn_80244A84(u8 *arg0, s32 arg1, u8 arg2, u8 arg3, u32 arg4, s32 arg5) {
    u8 *p;
    s32 r4;

    p = (u8 *)fn_8022EFF8(2);
    if (p == 0) {
        return 0;
    }
    *(u16 *)(p + 0x2) = 0x10;
    *(u16 *)(p + 0x4) = 0;
    r4 = arg1 >> 8;
    p[0x8] = 5;
    p[0x9] = 4;
    p[0xA] = 0xD;
    p[0xB] = arg0[0x5];
    p[0xC] = arg0[0x4];
    p[0xD] = arg0[0x3];
    p[0xE] = arg0[0x2];
    p[0xF] = arg0[0x1];
    p[0x10] = arg0[0x0];
    p[0x11] = (u8)arg1;
    p[0x12] = (u8)r4;
    p[0x13] = arg2;
    p[0x14] = arg3;
    p[0x15] = (u8)arg4;
    p[0x16] = (u8)((arg4 >> 8) & 0xFF);
    p[0x17] = (u8)arg5;
    fn_80242908(p);
    return 1;
}