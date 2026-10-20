#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 a : 4;
    s32 b : 4;
    u32 c : 24;
};

extern "C" {
s32 fn_27_1D08D4(Obj *p) {
    return p->b;
}
}
