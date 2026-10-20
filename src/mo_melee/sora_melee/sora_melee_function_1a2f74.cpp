#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    char pad[8];
    u32 field;
};

extern "C" {
s32 fn_27_1A2F74(Obj* p) {
    return (s32)((p->field << 6) & 0xFE000000) >> 26;
}
}
