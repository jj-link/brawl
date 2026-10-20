#pragma force_active on
struct S8 {
    unsigned int a : 6;
    unsigned int f : 6;
    unsigned int b : 20;
};

extern "C" void fn_27_19E674(unsigned int *p, unsigned int v) {
    struct S8 *s = (struct S8 *)(p + 2);
    s->f = v;
}
