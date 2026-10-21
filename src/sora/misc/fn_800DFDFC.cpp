#pragma force_active on
// Release a heap allocation when requested, preserving its original pointer.
extern "C" {
void __dl__FPv(void*);
void* fn_800DFDFC(void*, int);
}

void* fn_800DFDFC(void* ptr, int destroy) {
    if (ptr != 0 && destroy > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
