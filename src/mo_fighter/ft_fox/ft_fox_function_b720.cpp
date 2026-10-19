#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" s32 fn_97_B778();

extern "C" float fn_97_B720(u8* base, s32 unused, s32 a, s32 b) {
    u8* row = base + fn_97_B778() * 0x78;
    float* p = *(float**)(row + a * 4 - 0x3E70);
    return p[b];
}
