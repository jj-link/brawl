#pragma force_active on
typedef signed int s32;

extern "C" {
void __dl__FPv(void*);
void* fn_27_7CCFC(void* ptr, s32 count);
}

void* fn_27_7CCFC(void* ptr, s32 count) {
    if (ptr != 0 && count > 0)
        __dl__FPv(ptr);
    return ptr;
}
