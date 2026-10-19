#pragma force_active on
extern "C" void* fn_113_9B4(void* ptr, short flag);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_958(void* r3, short r4) {
    if (r3 != 0) {
        short z = 0;
        fn_113_9B4(r3, z);
        if (r4 > 0) {
            __dl__FPv(r3);
        }
    }
    return r3;
}
