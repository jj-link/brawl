#pragma force_active on
extern "C" void __dla__FPv(void*);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_8015B17C(void*, int);

struct Object {
    void* p0;
    void* p4;
    void* p8;
    void* pC;
    int n10;
    void* p14;
    void* p18;
    int n1C;
    int n20;
};

extern "C" Object* fn_80158BEC(Object* p, int flags) {
    if (p) {
        if (p->p0) {
            __dla__FPv(p->p0);
            p->p0 = 0;
        }
        if (p->p4) {
            __dla__FPv(p->p4);
            p->p4 = 0;
        }
        if (p->pC) {
            __dla__FPv(p->pC);
            p->pC = 0;
        }
        p->n10 = 0;
        if (p->p14) {
            __dla__FPv(p->p14);
            p->p14 = 0;
        }
        p->n1C = 0;
        if (p->p18) {
            __dla__FPv(p->p18);
            p->p18 = 0;
        }
        p->n20 = 0;
        if (p->p8) {
            fn_8015B17C(p->p8, 1);
        }
        p->p8 = 0;
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
