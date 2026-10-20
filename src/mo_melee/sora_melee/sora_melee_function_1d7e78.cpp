#pragma force_active on
typedef unsigned int u32;

struct Obj {
    int unk0;
    int unk4;
    u32 flags;
};

extern "C" void fn_27_1D7E78(Obj* p) {
    p->flags &= ~0x00010000;
}
