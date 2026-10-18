#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_62_57CC(void* ptr, int size)
{
    if (ptr != 0 && size > 0)
        __dl__FPv(ptr);
    return ptr;
}
