#pragma force_active on
extern "C" void __dt__10grYakumonoFv(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_54_2CB0(void* p, int del) {
    if (p != 0) {
        __dt__10grYakumonoFv(p, 0);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
