#pragma force_active on
extern "C" {
    extern void fn_27_240848(void*, int);
    extern void __dl__FPv(void*);

    void* fn_27_241184(void* a, int b) {
        if (a) {
            fn_27_240848(a, 0);
            if (b > 0)
                __dl__FPv(a);
        }
        return a;
    }
}
