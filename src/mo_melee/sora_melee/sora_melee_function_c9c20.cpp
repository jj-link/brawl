#pragma force_active on
struct Obj {
    int pad[2];
    unsigned int a : 3;
    unsigned int rest : 29;
};

extern "C" void fn_27_C9C20(Obj* p, unsigned int v) {
    p->a = v;
}
