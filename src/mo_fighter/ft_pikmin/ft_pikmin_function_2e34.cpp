#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_2E34(void* ptr, short shouldDelete)
{
    if (ptr != 0 && shouldDelete > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
