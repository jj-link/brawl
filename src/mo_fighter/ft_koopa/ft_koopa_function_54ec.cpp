#pragma force_active on
extern "C" void fn_27_66114(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_54EC(void* arg0, short arg1) {
    if (arg0) {
        fn_27_66114(arg0, -1);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
