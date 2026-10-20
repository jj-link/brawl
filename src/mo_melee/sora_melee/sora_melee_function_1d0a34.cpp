#pragma force_active on
struct Obj {
    unsigned char pad[8];
    unsigned int mode : 3;
    unsigned int rest : 29;
};

extern "C" void fn_27_1D0A34(Obj* p, unsigned int v) {
    p->mode = v;
}
