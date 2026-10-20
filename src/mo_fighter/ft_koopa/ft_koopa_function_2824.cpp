#pragma force_active on
typedef int s32;
typedef short s16;

extern "C" void* fn_27_1A63E8(void* p, s16 n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_102_2824(void* p, s16 n) {
    if (p != 0) {
        fn_27_1A63E8(p, -1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
