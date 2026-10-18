#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_2DC4C(void* ptr, short count)
{
    if (ptr != 0 && count > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
