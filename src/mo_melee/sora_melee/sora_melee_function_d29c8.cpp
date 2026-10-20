#pragma force_active on
typedef unsigned int u32;

struct FnObj {
    char pad[8];
    u32 flags;
};

extern "C" {
void fn_27_D29C8(FnObj* p) {
    p->flags &= 0xFFBFFFFF;
}
}
