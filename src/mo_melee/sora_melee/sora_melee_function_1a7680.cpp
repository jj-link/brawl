#pragma force_active on
typedef unsigned int u32;

struct FnObj {
    u32 pad0;
    u32 pad4;
    u32 flags;
};

extern "C" {
void fn_27_1A7680(FnObj* p) {
    p->flags &= ~0x80000;
}
}
