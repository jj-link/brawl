#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 pad0;
    u32 pad1;
    u32 flags;
};

extern "C" {
void fn_40_288F8(Obj* p) {
    p->flags &= ~0x02000000;
}
}
