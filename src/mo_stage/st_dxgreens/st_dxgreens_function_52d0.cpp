#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);

void* fn_79_52D0(void* ptr, int count);
}

void* fn_79_52D0(void* ptr, int count) {
    if (ptr != 0 && count > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
