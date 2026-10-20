#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct FnArg {
    u32 pad[2];
    u32 field;
};

extern "C" s32 fn_27_38D20(FnArg* p) {
    u32 v = (p->field >> 19) & 0x1F;
    return ((s32)(v << 27)) >> 28;
}
