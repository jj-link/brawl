#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_105_48D8(void*, short);

extern "C" void* fn_105_17C60(void* arg0, short arg1) {
    if (arg0) {
        short s = 0;
        fn_105_48D8(arg0, s);
        short t = arg1;
        if (t > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
