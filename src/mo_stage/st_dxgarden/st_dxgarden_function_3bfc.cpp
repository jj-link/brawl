#pragma force_active on
struct Obj77 {
    char pad[8];
    unsigned int flags;
};

extern "C" void fn_77_3BFC(Obj77* p) {
    p->flags |= 0x2000000;
}
