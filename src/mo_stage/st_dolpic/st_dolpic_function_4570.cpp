#pragma force_active on
extern "C" {
extern void __dt__10grYakumonoFv(void* p, int flag);
extern void __dl__FPv(void* p);
}

extern "C" void* fn_46_4570(void* p, int flag) {
    if (p) {
        __dt__10grYakumonoFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
