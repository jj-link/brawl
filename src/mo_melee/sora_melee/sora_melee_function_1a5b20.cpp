#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_1A5B20_arg {
    char pad[8];
    u32 word8;
};

extern "C" s32 fn_27_1A5B20(fn_27_1A5B20_arg* p) {
    return ((s32)((p->word8 << 10) & 0xFFE00000u)) >> 22;
}
