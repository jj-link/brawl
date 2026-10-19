#pragma force_active on
typedef short s16;

extern "C" void fn_94_1AD0(void* p, s16 x);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_94_1B90(void* p, s16 flag) {
    if (p != 0) {
        fn_94_1AD0(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
