#pragma force_active on
struct Obj124E00 {
    char pad[8];
    unsigned int flags;
};

extern "C" {
void fn_27_124E00(Obj124E00* p) {
    p->flags &= ~0x2000;
}
}
