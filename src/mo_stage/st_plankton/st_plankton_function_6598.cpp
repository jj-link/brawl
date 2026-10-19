#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_74_6598(void* p1, int p2)
{
    if (p1 != 0 && p2 > 0)
        __dl__FPv(p1);
    return p1;
}
