#pragma force_active on
struct Obj {
    unsigned int a;
    unsigned int b;
    unsigned int pad : 5;
    unsigned int field : 5;
    unsigned int rest : 22;
};

extern "C" {
void fn_27_B043C(Obj* p, unsigned int v) {
    p->field = v;
}
}
