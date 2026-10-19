#pragma force_active on
typedef signed short s16;

extern "C" void fn_27_1A4570(void* p, s16 n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_107_6AD0(void* p, s16 flag) {
    if (p != 0) {
        fn_27_1A4570(p, (s16)-1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
