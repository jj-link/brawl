#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_1A17B0_arg {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" s32 fn_27_1A17B0(fn_27_1A17B0_arg* p) {
    u32 x = p->unk8;
    u32 r = (x << 6) | (x >> 26);
    return ((s32)(r & 0xFE000000u)) >> 26;
}
