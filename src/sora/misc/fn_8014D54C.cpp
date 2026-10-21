#pragma force_active on
extern "C" int fn_8014DD34(void*, int);
extern "C" void fn_803A0158();
extern "C" void fn_803A01D0(int);
extern "C" void fn_803A0240(void*);

extern "C" void fn_8014D54C(void* a, void* b) {
    if (fn_8014DD34(a, 1)) {
        fn_803A0158();
        fn_803A01D0(1);
        fn_803A0240(b);
    }
}
