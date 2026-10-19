#pragma force_active on
extern "C" void fn_110_342C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_33D0(void* object, short count) {
    if (object != 0) {
        fn_110_342C(object, 0);
        if (count > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
