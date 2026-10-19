#pragma force_active on
extern "C" void* fn_27_1A09B4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_2330(void* object, short destroy) {
    if (object != 0) {
        fn_27_1A09B4(object, -1);
        if (destroy > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
