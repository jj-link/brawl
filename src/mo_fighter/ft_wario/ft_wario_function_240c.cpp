#pragma force_active on
extern "C" void* fn_27_1A09B4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_240C(void* object, short shouldDelete) {
    if (object != 0) {
        fn_27_1A09B4(object, static_cast<short>(-1));
        if (shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
