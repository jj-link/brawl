#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_62_5E9C(void* ptr, int deleteFlag)
{
    if (ptr != 0 && deleteFlag > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
