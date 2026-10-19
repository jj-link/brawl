#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_70_7DF8(void* ptr, int flag) {
    if (ptr != 0 && flag > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
