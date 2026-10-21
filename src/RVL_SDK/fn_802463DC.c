#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_80242908(void *p);

void fn_802463DC(void *p, u32 x) {
    u8 *b = (u8 *)p;
    *(u16 *)(b + 0x2) = 5;
    *(u16 *)(b + 0x4) = 0;
    b[0x8] = 0x18;
    b[0x9] = 0xC;
    b[0xA] = 2;
    b[0xB] = (u8)x;
    b[0xC] = (u8)(x >> 8);
    fn_80242908(p);
}
