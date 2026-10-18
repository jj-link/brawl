#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_40C0(void* ptr, int size) {
    if (ptr != 0 && (short)size > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
