#pragma force_active on
extern "C" void fn_81_4F40(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_81_5EE4(void* ptr, int size) {
    if (ptr != 0) {
        fn_81_4F40(ptr, 0);
        if (size > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
