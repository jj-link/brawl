#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    char pad[8];
    u32 field;
};

extern "C" s32 fn_27_CC6D8(Obj* p) {
    return (s32)((p->field << 3) & 0xF0000000) >> 29;
}
