#pragma force_active on
typedef unsigned int u32;

struct FooObj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_27_1CFFBC(FooObj* p) {
    p->flags &= ~0x80000;
}
}
