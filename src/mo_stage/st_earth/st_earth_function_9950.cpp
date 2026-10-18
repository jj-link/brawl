#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_66_9950(void* ptr, int size) {
    if (ptr != 0 && size > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
