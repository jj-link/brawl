#pragma force_active on
struct S {
    unsigned int pad[2];
    unsigned int hi : 6;
    unsigned int f : 6;
    unsigned int lo : 20;
};

extern "C" void fn_27_1A17C0(S* p, unsigned int v) {
    p->f = v;
}
