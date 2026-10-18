#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_D8AC(void* ptr, short size) {
    if (ptr != 0 && size > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
