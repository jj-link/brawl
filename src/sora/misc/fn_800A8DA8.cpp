#pragma force_active on
struct A {
    int pad[2];
    int value;
    int pad2[13];
    int arg;
};

extern "C" void fn_800A709C(struct A*, int);

extern "C" void fn_800A8DA8(struct A* a, int v) {
    a->value = v;
    fn_800A709C(a, a->arg);
}
