#pragma force_active on
typedef unsigned int u32;

struct Obj60 {
    char pad[8];
    u32 flags;
};

extern "C" void fn_27_19FBE8(Obj60* p) {
    p->flags &= ~0x00400000u;
}
