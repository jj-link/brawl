#pragma force_active on
extern "C" void fn_27_3797E8(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" int fn_27_37978C(int a, int b) {
    int ret = a;
    if (a != 0) {
        int c = b;
        fn_27_3797E8((void*)(a + 4), -1);
        if (c > 0) {
            __dl__FPv((void*)a);
        }
    }
    return ret;
}
