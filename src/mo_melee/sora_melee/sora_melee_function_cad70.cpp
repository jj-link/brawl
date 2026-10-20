#pragma force_active on
typedef unsigned int u32;

struct FnObj27 {
    char pad[8];
    u32 flags;
};

extern "C" void fn_27_CAD70(FnObj27 *p) {
    p->flags &= ~0x80000;
}
