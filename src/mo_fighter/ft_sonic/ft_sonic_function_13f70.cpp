#pragma force_active on
extern "C" void* fn_123_5094(void* ptr, short count);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_13F70(void* ptr, short count) {
    if (ptr != 0) {
        fn_123_5094(ptr, 0);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
