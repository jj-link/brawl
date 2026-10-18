#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_F56C(void* ptr, int flag) {
    if (ptr != 0 && (short)flag > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
