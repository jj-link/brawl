#pragma force_active on
typedef unsigned int u32;

struct FnFlags {
    char pad[8];
    u32 flags;
};

extern "C" void fn_27_1D057C(FnFlags* p) {
    p->flags &= ~0x2000;
}
