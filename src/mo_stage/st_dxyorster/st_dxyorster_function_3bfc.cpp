#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_76_3BFC(void* ptr, int flags) {
    if (ptr != 0 && flags > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
