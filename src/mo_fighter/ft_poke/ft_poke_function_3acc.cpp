#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_116_3B28(void* ptr, short size);

extern "C" void* fn_116_3ACC(void* ptr, short size)
{
    if (ptr != 0) {
        fn_116_3B28(ptr, 0);
        if (size > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
