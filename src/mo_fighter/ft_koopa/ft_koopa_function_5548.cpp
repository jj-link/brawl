#pragma force_active on
extern "C" void fn_27_64D9C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_5548(void* param0, short param1) {
    if (param0 != 0) {
        fn_27_64D9C(param0, -1);
        if (param1 > 0) {
            __dl__FPv(param0);
        }
    }
    return param0;
}
