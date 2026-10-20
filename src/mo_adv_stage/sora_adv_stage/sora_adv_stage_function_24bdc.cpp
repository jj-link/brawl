#pragma force_active on
struct Obj {
    int pad[2];
    unsigned int hi : 4;
    unsigned int f : 2;
    unsigned int rest : 26;
};

extern "C" void fn_40_24BDC(Obj* self, unsigned int v) {
    self->f = v;
}
