#pragma force_active on
extern "C" void* fn_27_14CD30(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_2B58(void* object, int count) {
    if (object != 0) {
        fn_27_14CD30(object, -1);
        if (static_cast<short>(count) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
