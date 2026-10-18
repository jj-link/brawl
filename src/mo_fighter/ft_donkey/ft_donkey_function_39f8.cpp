#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_39F8(void* ptr, short count)
{
    if (ptr != 0 && count > 0)
        __dl__FPv(ptr);
    return ptr;
}
