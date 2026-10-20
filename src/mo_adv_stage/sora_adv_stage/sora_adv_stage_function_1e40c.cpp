#pragma force_active on
struct Obj {
    int pad[2];
    unsigned int f : 6;
};

extern "C" void fn_40_1E40C(Obj* o, unsigned int v) {
    o->f = v;
}
