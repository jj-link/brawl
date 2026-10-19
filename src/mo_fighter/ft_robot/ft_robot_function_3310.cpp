#pragma force_active on
extern "C" void fn_120_336C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_3310(void* object, short shouldDelete) {
    if (object != 0) {
        fn_120_336C(object, 0);
        if (shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
