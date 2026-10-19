#pragma force_active on
extern "C" {
void __dt__10grYakumonoFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_77_F54(void* p, int flags) {
    if (p != 0) {
        __dt__10grYakumonoFv(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
