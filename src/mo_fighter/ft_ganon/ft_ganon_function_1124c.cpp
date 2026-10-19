#pragma force_active on
extern "C" void* fn_109_1120C(void* ptr, short size);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_1124C(void* ptr, short size)
{
    if (ptr != 0) {
        fn_109_1120C(ptr, 0);
        if (size > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
