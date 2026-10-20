#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn27Obj {
    char pad[8];
    u32 field;
};

extern "C" s32 fn_27_1A5814(fn27Obj* p) {
    return ((s32)((p->field << 4) & 0xF8000000u)) >> 28;
}
