#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_40_299E4(void* ptr, int shouldDelete) {
    if (ptr && shouldDelete > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
