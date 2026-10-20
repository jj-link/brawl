#pragma force_active on
struct Obj {
    char pad[8];
    unsigned int hi : 4;
    unsigned int f : 2;
    unsigned int lo : 26;
};

extern "C" void fn_27_C9E3C(Obj* p, unsigned int v) {
    p->f = v;
}
