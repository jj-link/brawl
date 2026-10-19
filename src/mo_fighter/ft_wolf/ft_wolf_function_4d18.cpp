#pragma force_active on
extern "C" void* fn_27_C31CC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_4D18(void* object, int size) {
    if (object != 0) {
        fn_27_C31CC(object, -1);
        if (static_cast<short>(size) > 0)
            __dl__FPv(object);
    }
    return object;
}
