#pragma force_active on
extern "C" void fn_27_3544C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_4C2C(void* arg1, short arg2) {
    if (arg1 != 0) {
        fn_27_3544C(arg1, -1);
        if (arg2 > 0) {
            __dl__FPv(arg1);
        }
    }
    return arg1;
}
