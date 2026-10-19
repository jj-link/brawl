#pragma force_active on
extern "C" void* fn_27_3544C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_5350(void* object, int count) {
    if (object != 0) {
        fn_27_3544C(object, static_cast<short>(-1));
        if (static_cast<short>(count) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
