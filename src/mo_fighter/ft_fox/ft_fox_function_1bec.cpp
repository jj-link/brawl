#pragma force_active on
extern "C" void fn_97_1B88(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_1BEC(void* object, short flags) {
    if (object != 0) {
        fn_97_1B88(object, 0);
        if (flags > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
