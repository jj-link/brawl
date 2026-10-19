#pragma force_active on
extern "C" {
void __dt__10grYakumonoFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_73_2CC8(void* p, int n) {
    if (p) {
        __dt__10grYakumonoFv(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
