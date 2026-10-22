#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern void* fn_8022EFF8(int);
extern void fn_80242908(void*);

s32 fn_80245288(u32 arg0) {
    u8* p;

    p = (u8*)fn_8022EFF8(2);
    if (p == 0) {
        return 0;
    }
    *(u16*)(p + 0x2) = 5;
    *(u16*)(p + 0x4) = 0;
    *(u8*)(p + 0x8) = 0x11;
    *(u8*)(p + 0x9) = 4;
    *(u8*)(p + 0xA) = 2;
    *(u8*)(p + 0xB) = (u8)arg0;
    *(u8*)(p + 0xC) = (u8)((arg0 >> 8) & 0xFF);
    fn_80242908(p);
    return 1;
}
