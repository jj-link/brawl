#pragma force_active on
// Release a heap block when requested, preserving its original pointer.
extern "C" {
void __dl__FPv(void*);
void* fn_27_CBB00(void*, int);
}

extern "C" void* fn_27_CBB00(void* ptr, int size) {
    if (ptr != 0 && size > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
