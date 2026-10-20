#pragma force_active on
struct S {
    int pad[2];
    unsigned int hi : 10;
    unsigned int f : 5;
    unsigned int lo : 17;
};

extern "C" void fn_27_7626C(S* p, unsigned int v) {
    p->f = v;
}
