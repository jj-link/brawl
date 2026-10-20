#pragma force_active on
struct Obj {
    unsigned int pad[2];
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int c : 28;
};

extern "C" {
void fn_40_249F0(Obj* p, unsigned int v) {
    p->b = v;
}
}
