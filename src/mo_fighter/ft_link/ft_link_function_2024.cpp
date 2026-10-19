#pragma force_active on
extern "C" void fn_27_3544C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_2024(void* object, short flag) {
    if (object != 0) {
        fn_27_3544C(object, static_cast<short>(-1));
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
