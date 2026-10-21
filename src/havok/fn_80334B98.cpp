#pragma force_active on
typedef struct {
    int f0;
    int f4;
    int f8;
} Triple;

extern "C" {
void fn_80334B98(Triple* a, Triple* b) {
    int t;
    t = a->f0;
    a->f0 = b->f0;
    b->f0 = t;
    t = a->f4;
    a->f4 = b->f4;
    b->f4 = t;
    t = a->f8;
    a->f8 = b->f8;
    b->f8 = t;
}
}
