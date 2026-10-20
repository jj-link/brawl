#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_19EDB4_Arg {
    u32 unk0;
    u32 unk4;
    u32 unk8 : 10;
    s32 unk18 : 5;
    u32 unk23 : 17;
};

extern "C" s32 fn_27_19EDB4(fn_27_19EDB4_Arg* p) {
    return p->unk18;
}
