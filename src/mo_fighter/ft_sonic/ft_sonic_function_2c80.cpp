#pragma force_active on
extern "C" void fn_27_C21DC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_2C80(void* object, int destroy) {
    if (object != 0) {
        fn_27_C21DC(object, -1);
        if (static_cast<short>(destroy) > 0)
            __dl__FPv(object);
    }
    return object;
}
