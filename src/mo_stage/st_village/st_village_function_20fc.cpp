#pragma force_active on
extern "C" void __dt__10grYakumonoFv(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_70_20FC(void* p, int n) {
    if (p != 0) {
        __dt__10grYakumonoFv(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
