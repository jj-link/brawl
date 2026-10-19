#pragma force_active on
extern "C" void* fn_27_A0C34(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_2FB3C(void* object, int flag) {
    if (object != 0) {
        fn_27_A0C34(object, static_cast<short>(-1));
        if (static_cast<short>(flag) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
