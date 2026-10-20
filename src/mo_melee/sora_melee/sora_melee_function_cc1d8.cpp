#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_CC1D8_obj {
    u32 pad[2];
    u32 flags;
};

extern "C" s32 fn_27_CC1D8(fn_27_CC1D8_obj* p) {
    u32 t = (p->flags >> 25) & 7;
    return (s32)(t << 29) >> 30;
}
