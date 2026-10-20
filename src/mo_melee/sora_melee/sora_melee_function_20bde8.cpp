#pragma force_active on
typedef unsigned int u32;

typedef struct Pair {
    u32 a;
    u32 b;
} Pair;

extern const float lbl_27_rodata_2F90;

extern "C" Pair fn_27_20BDE8(char* self)
{
    char* p = *(char**)(self + 0xbc);
    float v = *(float*)(self + 0x5c);
    float lim = lbl_27_rodata_2F90 * (*(float*)(p + 0x18) + *(float*)(p + 0x20));
    Pair r;
    if (v < lim) {
        r = *(Pair*)(p + 0x18);
    } else {
        r = *(Pair*)(p + 0x20);
    }
    return r;
}
