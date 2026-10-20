#pragma force_active on
typedef unsigned int u32;

struct Fn27Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_27_390328(Fn27Obj* p) {
    p->flags &= 0xFFBFFFFF;
}
}
