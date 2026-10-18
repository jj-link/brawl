#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);

void* fn_63_A650(void* ptr, int size) {
    if (ptr && size > 0)
        __dl__FPv(ptr);
    return ptr;
}
}
