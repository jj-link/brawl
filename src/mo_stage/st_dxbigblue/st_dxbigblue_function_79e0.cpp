#pragma force_active on
extern "C" void fn_81_47BC(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_81_79E0(void* ptr, int shouldDelete) {
    if (ptr != 0) {
        fn_81_47BC(ptr, 0);
        if (shouldDelete > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
