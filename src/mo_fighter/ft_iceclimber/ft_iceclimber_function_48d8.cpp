#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_48D8(void* arg0, short arg1) {
    if (arg0 && arg1 > 0) {
        __dl__FPv(arg0);
    }
    return arg0;
}
