#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_34E1D0(void* ptr, int shouldDelete) {
    if (ptr != 0 && shouldDelete > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
