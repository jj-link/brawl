#pragma force_active on
struct FnState {
    char pad[8];
    unsigned int flags;
};

extern "C" {
void fn_27_CEED4(FnState* p) {
    p->flags &= ~0x2000u;
}
}
