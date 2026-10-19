#pragma force_active on
extern "C" {
void __dt__10grYakumonoFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_63_2C40(void* p, int flag) {
    if (p != 0) {
        __dt__10grYakumonoFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
