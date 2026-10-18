#pragma force_active on
extern "C" void* fn_115_3A88(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_3A2C(void* ptr, short shouldDelete) {
    if (ptr != 0) {
        fn_115_3A88(ptr, 0);
        if (shouldDelete > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
