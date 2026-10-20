#pragma force_active on
struct Obj {
    char pad[8];
    unsigned int f : 3;
    unsigned int rest : 29;
};

extern "C" {
void fn_27_1A1320(Obj* p, unsigned int v) {
    p->f = v;
}
}
