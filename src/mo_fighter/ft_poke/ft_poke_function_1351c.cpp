#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_1351C(void* ptr, int size)
{
    if (ptr != 0 && static_cast<short>(size) > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
