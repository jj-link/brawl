#pragma force_active on
extern "C" void* fn_27_5B39C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_42BC(void* param1, short param2) {
    if (param1) {
        fn_27_5B39C(param1, -1);
        if (param2 > 0) {
            __dl__FPv(param1);
        }
    }
    return param1;
}
