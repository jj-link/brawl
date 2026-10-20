#pragma force_active on
struct Obj {
    char pad[8];
    unsigned int a : 4;
    unsigned int b : 4;
    unsigned int c : 24;
};

extern "C" {
void fn_27_1CFED4(Obj* o, unsigned int v) {
    o->b = v;
}
}
