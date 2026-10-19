#pragma force_active on
extern "C" {
void fn_88_43CC(void* p, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_88_751C(void* p, int size)
{
    if (p != 0) {
        fn_88_43CC(p, 0);
        if (size > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
