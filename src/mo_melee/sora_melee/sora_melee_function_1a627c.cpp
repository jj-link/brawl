#pragma force_active on
struct FnObj {
    char pad[8];
    unsigned int flags;
};

extern "C" {
void fn_27_1A627C(FnObj* p) {
    p->flags &= ~0x2u;
}
}
