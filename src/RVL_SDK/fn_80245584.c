#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern u8* fn_8022EFF8(int);
extern void fn_80242908(void* p);

s32 fn_80245584(u32 arg0) {
    u8* p = fn_8022EFF8(2);
    if (p == 0) {
        return 0;
    }
    *(u16*)(p + 2) = 5;
    *(u16*)(p + 4) = 0;
    p[8] = 0x1D;
    p[9] = 4;
    p[10] = 2;
    p[11] = (u8)arg0;
    p[12] = (u8)((arg0 >> 8) & 0xFF);
    fn_80242908(p);
    return 1;
}
