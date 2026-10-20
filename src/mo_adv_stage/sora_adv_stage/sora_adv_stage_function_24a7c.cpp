#pragma force_active on
struct Obj {
    int pad0;
    int pad1;
    unsigned int hi : 4;
    unsigned int f : 2;
    unsigned int lo : 26;
};

extern "C" void fn_40_24A7C(Obj* o, int v) {
    o->f = v;
}
