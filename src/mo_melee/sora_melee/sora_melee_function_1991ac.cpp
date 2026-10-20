#pragma force_active on
typedef unsigned int u32;

struct fn27Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_27_1991AC(fn27Obj* p) {
    p->flags &= 0xFFBFFFFF;
}
}
