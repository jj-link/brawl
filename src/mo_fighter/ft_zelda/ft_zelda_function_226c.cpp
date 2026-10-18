#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_226C(void* p, short flag)
{
    if (p != 0 && flag > 0) {
        __dl__FPv(p);
    }
    return p;
}
