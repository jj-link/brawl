#pragma force_active on
class grYakumono;

extern "C" void __dt__10grYakumonoFv(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" {
grYakumono* fn_40_24E00(grYakumono* p, int del) {
    if (p) {
        __dt__10grYakumonoFv(p, 0);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
