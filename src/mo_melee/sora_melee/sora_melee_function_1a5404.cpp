#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    char pad[8];
    u32 field8;
};

extern "C" s32 fn_27_1A5404(Obj* p) {
    u32 x = p->field8;
    return ((s32)(((x >> 25) & 0xF) << 28)) >> 29;
}
