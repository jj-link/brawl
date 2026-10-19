#pragma force_active on
extern "C" {
void __dt__10grYakumonoFv(void* p, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_57_39EC(void* p, int del) {
    if (p) {
        __dt__10grYakumonoFv(p, 0);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
