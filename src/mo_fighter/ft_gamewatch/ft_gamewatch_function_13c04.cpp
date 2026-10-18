#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_13C04(void* ptr, short flags) {
    if (ptr != 0 && flags > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
