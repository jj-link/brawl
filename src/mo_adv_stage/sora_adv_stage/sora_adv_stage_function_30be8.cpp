#pragma force_active on
typedef unsigned int u32;

struct FnObj40 {
    u32 pad0;
    u32 pad4;
    u32 flags;
};

extern "C" void fn_40_30BE8(FnObj40* p) {
    p->flags |= 0x10000;
}
