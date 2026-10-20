#pragma force_active on
extern "C" void* fn_27_A1E80(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_1E0B94(void* arg1, short arg2) {
    if (arg1) {
        fn_27_A1E80(arg1, -1);
        if (arg2 > 0) {
            __dl__FPv(arg1);
        }
    }
    return arg1;
}
