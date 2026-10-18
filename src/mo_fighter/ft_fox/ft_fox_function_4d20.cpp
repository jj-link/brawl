#pragma force_active on
extern "C" void* fn_27_63EBC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_4D20(void* object, int count) {
    if (object != 0) {
        fn_27_63EBC(object, static_cast<short>(-1));
        if (static_cast<short>(count) > 0)
            __dl__FPv(object);
    }
    return object;
}
