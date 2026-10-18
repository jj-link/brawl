#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);

void* fn_122_152B0(void* p, short size)
{
    if (p != 0 && size > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
