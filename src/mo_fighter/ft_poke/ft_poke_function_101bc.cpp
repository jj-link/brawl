#pragma force_active on
extern "C" void* fn_116_4CE8(void* ptr, short flag);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_116_101BC(void* ptr, int flag)
{
    if (ptr != 0) {
        fn_116_4CE8(ptr, 0);
        if ((short)flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
