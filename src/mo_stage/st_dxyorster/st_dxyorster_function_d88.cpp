#pragma force_active on
extern "C" void __dt__10grYakumonoFv(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_76_D88(void* p, int flag)
{
    void* result = p;
    if (p != 0) {
        if (p != 0)
            __dt__10grYakumonoFv(p, 0);
        if (flag > 0)
            __dl__FPv(p);
    }
    return result;
}
