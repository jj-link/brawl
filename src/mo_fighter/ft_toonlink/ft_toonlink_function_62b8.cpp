#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_62B8(void* ptr, int flag) {
    if (ptr != 0 && (short)flag > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
