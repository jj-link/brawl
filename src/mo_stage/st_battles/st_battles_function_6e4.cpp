#pragma force_active on
extern "C" {
extern void __dt__10grYakumonoFv(void*, int);
extern void __dl__FPv(void*);

void* fn_42_6E4(void* p, int release) {
    if (p != 0) {
        __dt__10grYakumonoFv(p, 0);
        if (release > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
