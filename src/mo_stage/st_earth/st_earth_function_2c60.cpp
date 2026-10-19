#pragma force_active on
extern "C" {
void __dt__10grYakumonoFv(void*, int);
void __dl__FPv(void*);
void* fn_66_2C60(void* p, int n);
}

extern "C" void* fn_66_2C60(void* p, int n) {
    if (p) {
        __dt__10grYakumonoFv(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
