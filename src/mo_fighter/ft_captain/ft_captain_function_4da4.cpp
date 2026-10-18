#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_4DA4(void* ptr, short count) {
    if (ptr && count > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
