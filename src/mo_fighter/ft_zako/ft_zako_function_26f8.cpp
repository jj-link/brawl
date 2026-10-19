#pragma force_active on
typedef signed short s16;
typedef int s32;

extern "C" void* fn_27_1A59C0(void* p, s16 n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_126_26F8(void* p, s16 n) {
    if (p != 0) {
        s16 m = -1;
        fn_27_1A59C0(p, m);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
