#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_5EE8(void* ptr, int length)
{
    if (ptr != 0 && (short) length > 0)
        __dl__FPv(ptr);
    return ptr;
}
