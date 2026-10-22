#pragma force_active on
typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;

extern "C" void* fn_8027EA20(void*, unsigned int, int);
extern void* lbl_805A0EC8;

extern "C" void fn_802DA104(int arg0) {
    unsigned int size = (arg0 * 0x34 + 0x3F) & ~0xF;
    u8* p = (u8*)fn_8027EA20(lbl_805A0EC8, size, 4);
    *(s16*)(p + 0x8) = 0;
    *(s16*)(p + 0xA) = 3;
    *(u32*)(p + 0xC) = 0;
    *(u32*)(p + 0x10) = 0;
    *(u32*)(p + 0x14) = 0;
    *(u32*)(p + 0x18) = 0;
    *(u32*)(p + 0x1C) = 0;
    *(u32*)(p + 0x20) = 0;
    *(u32*)(p + 0x24) = 0;
    *(s16*)(p + 0x0) = 0x16;
    *(s16*)(p + 0x2) = size;
    *(s16*)(p + 0x4) = 0;
    *(s16*)(p + 0x6) = arg0;
}
