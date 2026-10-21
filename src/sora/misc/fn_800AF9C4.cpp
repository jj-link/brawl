#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
extern "C" u8 lbl_80455458[];

extern "C" u32 isCharLargeSize__6muMenuFiii(int this_, int a, int b, int c) {
    u8* p = (u8*)lbl_80455458 + (this_ << 4);
    u8 x = p[0xC];
    u32 t = (x >> 7) & 1;
    return (-t | t) >> 31;
}
