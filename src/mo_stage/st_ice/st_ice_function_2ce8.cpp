#pragma force_active on
extern "C" {
void __dt__10grYakumonoFv(void*, int);
void __dl__FPv(void*);

void* fn_62_2CE8(void* p, int flag)
{
    if (p) {
        __dt__10grYakumonoFv(p, 0);
        if (flag > 0)
            __dl__FPv(p);
    }
    return p;
}
}
