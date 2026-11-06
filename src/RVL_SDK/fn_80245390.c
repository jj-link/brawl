#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern void* fn_8022EFF8(int);
extern void fn_80242908(void* p);

s32 fn_80245390(u8* arg0, u8 arg1, u8 arg2, u32 arg3) {
    u8* p;

    p = (u8*)fn_8022EFF8(2);
    if (p == 0) {
        return 0;
    }
    *(u16*)(p + 0x2) = 0xD;
    *(u16*)(p + 0x4) = 0;
    p[0x8] = 0x19;
    p[0x9] = 4;
    p[0xA] = 0xA;
    p[0xB] = arg0[5];
    p[0xC] = arg0[4];
    p[0xD] = arg0[3];
    p[0xE] = arg0[2];
    p[0xF] = arg0[1];
    p[0x10] = arg0[0];
    p[0x11] = arg1;
    p[0x12] = arg2;
    p[0x13] = (u8)arg3;
    p[0x14] = (u8)((arg3 >> 8) & 0xFF);
    fn_80242908(p);
    return 1;
}
