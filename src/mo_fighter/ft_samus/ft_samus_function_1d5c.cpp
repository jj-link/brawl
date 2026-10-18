#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_1D5C(void* p, short n)
{
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
