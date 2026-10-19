#pragma force_active on
extern "C" void fn_27_1A66F4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_2864(void* r3, short r4) {
    if (r3 != 0) {
        fn_27_1A66F4(r3, -1);
        if (r4 > 0) {
            __dl__FPv(r3);
        }
    }
    return r3;
}
