#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_DB244_arg {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" s32 fn_27_DB244(fn_27_DB244_arg *p) {
    return (s32)((p->unk8 << 4) & 0xE0000000) >> 30;
}
