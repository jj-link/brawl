#pragma force_active on
extern "C" {
void __dt__10grYakumonoFv(void*, int);
void __dl__FPv(void*);

void* fn_88_43CC(void* p, int del)
{
    if (p) {
        __dt__10grYakumonoFv(p, 0);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
