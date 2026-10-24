#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef int s32;

extern void* fn_8022EFF8(s32);
extern void fn_80242908(void*);

s32 fn_80245304(u16 arg0, s8 arg1) {
    u8* p;

    p = (u8*)fn_8022EFF8(2);
    if (p == 0) {
        return 0;
    }
    *(u16*)(p + 0x2) = 6;
    *(u16*)(p + 0x4) = 0;
    p[0x8] = 0x13;
    p[0x9] = 4;
    p[0xA] = 3;
    p[0xB] = (u8)arg0;
    p[0xC] = (u8)(arg0 >> 8);
    p[0xD] = (u8)arg1;
    fn_80242908(p);
    return 1;
}
