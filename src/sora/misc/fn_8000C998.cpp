#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* __dt__Q34nw4r2ut5ColorFv(void* ptr, int destroyFlag) {
    if ((ptr != 0) && (destroyFlag > 0)) {
        __dl__FPv(ptr);
    }
    return ptr;
}
