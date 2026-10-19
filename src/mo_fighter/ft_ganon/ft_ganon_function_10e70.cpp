#pragma force_active on
extern "C" void* fn_109_44C8(void* ptr, short size);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_10E70(void* ptr, short size) {
    if (ptr != 0) {
        short ext = 0;
        fn_109_44C8(ptr, ext);
        if (size > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
