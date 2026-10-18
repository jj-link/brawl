#pragma force_active on
extern "C" void fn_100_1AD0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_1B90(void* ptr, int shouldDelete) {
    if (ptr != 0) {
        fn_100_1AD0(ptr, 0);
        if ((short)shouldDelete > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
