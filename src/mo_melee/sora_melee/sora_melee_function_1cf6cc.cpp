#pragma force_active on
struct Obj {
    char pad[8];
    unsigned int a : 5;
    unsigned int rest : 27;
};

extern "C" {
void fn_27_1CF6CC(Obj* p, unsigned int v) {
    p->a = v;
}
}
