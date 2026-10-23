#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void fn_8018CCC4(u8* p, u8 b, u32 v) {
    p[0] = 8;
    p[1] = b;
    p[2] = (u8)(v >> 24);
    p[3] = (u8)(v >> 16);
    p[4] = (u8)(v >> 8);
    p[5] = (u8)v;
}
