#pragma force_active on
class grYakumono;

extern "C" {
void __dt__10grYakumonoFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_61_2384(void* p, int del) {
    if (p != 0) {
        __dt__10grYakumonoFv(p, 0);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
