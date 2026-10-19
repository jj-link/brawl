#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_121_21A0(void*, short);

extern "C" void* fn_121_2144(void* ptr, short count) {
    if (ptr != 0) {
        fn_121_21A0(ptr, 0);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
