#pragma force_active on
struct Obj {
    int pad[2];
    unsigned int flags;
};

extern "C" void fn_40_30CAC(Obj* p) {
    p->flags &= 0xFFFEFFFF;
}
