#pragma force_active on
struct S {
    unsigned int pad[2];
    unsigned int hi : 4;
    unsigned int f : 4;
    unsigned int lo : 24;
};

extern "C" void fn_27_19D1EC(S* p, unsigned int v) {
    p->f = v;
}
