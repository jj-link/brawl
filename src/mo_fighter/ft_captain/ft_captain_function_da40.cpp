#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_DA40(void* p, short flag)
{
    if (p != 0 && flag > 0)
        __dl__FPv(p);
    return p;
}
