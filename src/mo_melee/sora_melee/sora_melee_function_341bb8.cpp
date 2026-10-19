#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_341BB8(void* ptr, int shouldDelete) {
    if (ptr != 0 && shouldDelete > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
