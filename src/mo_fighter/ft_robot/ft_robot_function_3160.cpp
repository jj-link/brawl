#pragma force_active on
extern "C" void* fn_27_19874C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_3160(void* object, int flag) {
    if (object != 0) {
        fn_27_19874C(object, static_cast<short>(-1));
        if (static_cast<short>(flag) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
