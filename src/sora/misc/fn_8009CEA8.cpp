#pragma force_active on
typedef float f32;
typedef unsigned char u8;

extern "C" void fn_8009CEA8(u8* p, const f32* s) {
    f32 o3, o2, o1, o0;
    f32 s3, s2, s1, s0;
    f32 y, x;

    x = *(f32*)(p + 0xA4) + *(f32*)(p + 0x168);
    y = *(f32*)(p + 0xA8) + *(f32*)(p + 0x16C);
    s0 = s[0];
    s1 = s[1];
    s2 = s[2];
    s3 = s[3];
    o0 = s0 + x;
    o1 = s1 + x;
    o2 = s2 + y;
    o3 = s3 + y;
    *(f32*)(p + 0x128) = s0;
    *(f32*)(p + 0x12C) = s1;
    *(f32*)(p + 0x130) = s2;
    *(f32*)(p + 0x134) = s3;
    *(f32*)(p + 0x148) = o0;
    *(f32*)(p + 0x14C) = o1;
    *(f32*)(p + 0x150) = o2;
    *(f32*)(p + 0x154) = o3;
}
