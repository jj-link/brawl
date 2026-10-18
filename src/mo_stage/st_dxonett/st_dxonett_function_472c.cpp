#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);

void* fn_78_472C(void* ptr, int count);
}

void* fn_78_472C(void* ptr, int count) {
    if (ptr != 0 && count > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
