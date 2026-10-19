#pragma force_active on
extern "C" void __dt__10grYakumonoFv(void* self, int flags);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_40_3C03C(void* p, int n) {
    if (p != 0) {
        __dt__10grYakumonoFv(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
