#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    char pad[8];
    u32 field;
};

extern "C" s32 fn_27_1A6AC0(Obj* p) {
    u32 w = p->field;
    u32 t = (w << 20) | (w >> 12);
    return (s32)(t & 0xFFE00000) >> 22;
}
