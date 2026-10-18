#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_F51C(void* ptr, short size) {
    if (ptr != 0 && size > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
