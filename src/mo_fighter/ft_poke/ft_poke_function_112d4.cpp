#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_112D4(void* ptr, int count) {
    if (ptr && (short)count > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
