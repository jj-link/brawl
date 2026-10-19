#pragma force_active on
extern "C" void* fn_27_63EBC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_3B68(void* object, int shouldDelete) {
    if (object != 0) {
        fn_27_63EBC(object, static_cast<short>(-1));
        if (static_cast<short>(shouldDelete) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
