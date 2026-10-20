#pragma force_active on
struct Obj {
    char pad[8];
    unsigned int mode : 2;
};

extern "C" void fn_40_288B8(Obj* p, unsigned int v) {
    p->mode = v;
}
