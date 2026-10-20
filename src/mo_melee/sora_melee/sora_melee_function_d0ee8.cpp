#pragma force_active on
struct S {
    unsigned int hi : 14;
    unsigned int f : 7;
    unsigned int lo : 11;
};

extern "C" void fn_27_D0EE8(unsigned int *p, unsigned int v) {
    S *s = (S *)&p[2];
    s->f = v;
}
