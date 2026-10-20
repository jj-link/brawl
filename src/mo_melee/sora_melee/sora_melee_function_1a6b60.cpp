#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_1A6B60_Arg {
    u32 unk0;
    u32 unk4;
    u32 value;
};

extern "C" s32 fn_27_1A6B60(fn_27_1A6B60_Arg* p) {
    return (s32)((p->value << 10) & 0xFFE00000) >> 22;
}
