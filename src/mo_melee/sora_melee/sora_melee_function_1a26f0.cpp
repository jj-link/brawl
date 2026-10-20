#pragma force_active on
typedef unsigned int u32;

struct Obj {
    char pad[8];
    u32 flags;
};

extern "C" void fn_27_1A26F0(Obj* p) {
    p->flags &= ~0x80000u;
}
