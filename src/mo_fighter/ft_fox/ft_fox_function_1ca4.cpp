#pragma force_active on
extern "C" void fn_97_1B88(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_1CA4(void* object, short destroy) {
    if (object != 0) {
        fn_97_1B88(object, 0);
        if (destroy > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
