#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_74_6034(void* ptr, int size) {
    if (ptr && size > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
