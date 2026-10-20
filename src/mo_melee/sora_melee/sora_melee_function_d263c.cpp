#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 pad0;
    u32 pad1;
    u32 flags;
};

extern "C" void fn_27_D263C(Obj *p) {
    p->flags &= ~0x02000000u;
}
