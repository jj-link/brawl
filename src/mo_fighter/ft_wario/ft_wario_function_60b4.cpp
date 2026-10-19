#pragma force_active on
extern "C" void fn_27_1540CC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_60B4(void* object, int release) {
    if (object != 0) {
        fn_27_1540CC(object, -1);
        if ((short)release > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
