#pragma force_active on
typedef int s32;
typedef short s16;

extern "C" {
    extern void fn_104_1B48(void* a, s16 b);
    extern void __dl__FPv(void*);

    void* fn_104_1C08(void* arg1, s16 arg2) {
        if (arg1) {
            fn_104_1B48(arg1, 0);
            if (arg2 > 0) {
                __dl__FPv(arg1);
            }
        }
        return arg1;
    }
}
