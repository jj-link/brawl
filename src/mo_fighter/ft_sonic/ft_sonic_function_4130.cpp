#pragma force_active on
extern "C" void* fn_27_5AE44(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_4130(void* object, int count) {
    if (object != 0) {
        fn_27_5AE44(object, -1);
        if (static_cast<short>(count) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
