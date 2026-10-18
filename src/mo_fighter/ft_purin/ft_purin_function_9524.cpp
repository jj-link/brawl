#pragma force_active on
extern "C" void fn_124_8414(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_9524(void* ptr, short flag)
{
    if (ptr != 0) {
        if (ptr != 0) {
            fn_124_8414(ptr, 0);
        }
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
