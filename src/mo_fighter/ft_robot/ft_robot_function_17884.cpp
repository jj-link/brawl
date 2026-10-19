#pragma force_active on
extern "C" void* fn_27_5AE44(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_17884(void* object, int flag) {
    if (object != 0) {
        fn_27_5AE44(object, -1);
        if (static_cast<short>(flag) > 0)
            __dl__FPv(object);
    }
    return object;
}
