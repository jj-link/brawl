#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_2_300C(void* ptr, int flag)
{
    if ((int)ptr != 0) {
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
