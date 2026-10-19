#pragma force_active on
extern "C" void fn_121_1BB4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_1C74(void* ptr, short release) {
    if (ptr != 0) {
        fn_121_1BB4(ptr, 0);
        if (release > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
