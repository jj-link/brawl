#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u32 pad[2];
    u32 v;
};

extern "C" {
s32 fn_27_1D0484(Obj* p) {
    return (s32)((p->v << 7) & 0xFF000000) >> 25;
}
}
