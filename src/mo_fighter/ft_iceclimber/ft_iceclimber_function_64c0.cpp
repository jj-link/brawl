#pragma force_active on
typedef short s16;

extern "C" void fn_27_1A3A44(void* p, s16 n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_105_64C0(void* p, s16 n) {
    if (p != 0) {
        fn_27_1A3A44(p, -1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
