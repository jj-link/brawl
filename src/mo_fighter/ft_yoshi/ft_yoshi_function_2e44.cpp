#pragma force_active on
extern "C" void* fn_27_BED74(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_2E44(void* param1, short param2) {
    if (param1 != 0) {
        fn_27_BED74(param1, -1);
        if (param2 > 0) {
            __dl__FPv(param1);
        }
    }
    return param1;
}
