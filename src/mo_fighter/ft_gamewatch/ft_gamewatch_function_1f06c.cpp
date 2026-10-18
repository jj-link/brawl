#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_1F06C(void* ptr, short flag) {
    if (ptr != 0 && flag > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
