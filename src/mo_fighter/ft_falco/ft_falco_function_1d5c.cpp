#pragma force_active on
extern "C" void fn_108_1B2C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_1D5C(void* object, short shouldDelete) {
    if (object != 0) {
        fn_108_1B2C(object, 0);
        if (shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
