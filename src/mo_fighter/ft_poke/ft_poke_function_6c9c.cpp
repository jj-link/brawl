#pragma force_active on
extern "C" void fn_27_1A75E4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_6C9C(void* object, short flag) {
    if (object != 0) {
        fn_27_1A75E4(object, static_cast<short>(-1));
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
