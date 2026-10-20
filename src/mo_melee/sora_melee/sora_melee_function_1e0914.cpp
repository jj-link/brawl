#pragma force_active on
extern "C" void* fn_27_5C674(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_1E0914(void* arg1, int arg2) {
    if (arg1) {
        fn_27_5C674(arg1, -1);
        if (arg2 > 0) {
            __dl__FPv(arg1);
        }
    }
    return arg1;
}
