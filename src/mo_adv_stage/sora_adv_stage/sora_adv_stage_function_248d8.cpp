#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    int pad[2];
    u32 v;
};

extern "C" {
s32 fn_40_248D8(Obj* p) {
    return ((s32)((p->v << 2) & 0xE0000000)) >> 30;
}
}
