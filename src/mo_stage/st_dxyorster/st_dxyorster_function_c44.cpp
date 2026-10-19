#pragma force_active on
extern "C" {
void __dt__10grYakumonoFv(void*, int);
void __dl__FPv(void*);
void* fn_76_C44(void* p, int n);
}

void* fn_76_C44(void* p, int n) {
    if (p) {
        __dt__10grYakumonoFv(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
