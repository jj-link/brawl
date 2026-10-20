#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Inner { u32 w[4]; };

extern const u32 lbl_27_data_4C290[7];

extern "C" void fn_27_236D48(u32* p, u32* b, Inner* src, u8 d) {
    p[0] = 0;
    p[2] = (u32)b;
    *(u8*)((char*)p + 0xC) = d;
    p[1] = (u32)lbl_27_data_4C290;
    *(Inner*)(void*)(p + 4) = *src;
}
