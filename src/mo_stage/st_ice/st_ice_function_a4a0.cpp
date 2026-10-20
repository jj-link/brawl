#pragma force_active on
struct S {
    int pad[2];
    unsigned int flags;
};

extern "C" void fn_62_A4A0(S *p) {
    p->flags &= ~0x02000000u;
}
