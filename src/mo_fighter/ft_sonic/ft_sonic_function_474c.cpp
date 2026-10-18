#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_474C(void* ptr, short release) {
    if (ptr != 0 && release > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
