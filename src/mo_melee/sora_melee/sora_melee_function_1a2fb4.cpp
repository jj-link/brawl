#pragma force_active on
typedef unsigned int u32;

struct Obj1A2FB4 {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_1A2FB4(Obj1A2FB4* p) {
    p->flags &= ~0x2000;
}
