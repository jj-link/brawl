#pragma force_active on
extern "C" void* fn_100_4D24(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_132E4(void* ptr, short size) {
    if (ptr != 0) {
        fn_100_4D24(ptr, 0);
        if (size > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
