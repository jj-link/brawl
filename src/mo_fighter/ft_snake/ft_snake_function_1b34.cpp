#pragma force_active on
extern "C" {
    typedef signed short s16;
    typedef signed int s32;

    void fn_122_1AD0(void*, s16);
    void __dl__FPv(void*);

    void* fn_122_1B34(void* a, s16 b) {
        if (a != 0) {
            fn_122_1AD0(a, 0);
            if (b > 0) {
                __dl__FPv(a);
            }
        }
        return a;
    }
}
