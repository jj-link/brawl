#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_47B0(void* ptr, short count) {
    if (ptr && count > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
