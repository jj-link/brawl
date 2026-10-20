#pragma force_active on
typedef unsigned int u32;

struct FlagObj {
    char pad[8];
    u32 flags;
};

extern "C" void fn_27_19DB3C(FlagObj* p) {
    p->flags &= 0xFFFEFFFF;
}
