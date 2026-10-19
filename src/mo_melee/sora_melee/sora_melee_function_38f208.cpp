#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_38F208(void* ptr, int val) {
    if (ptr && val > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
