#pragma force_active on
extern "C" void fn_27_1540CC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_7460(void* object, int destroy) {
    if (object != 0) {
        fn_27_1540CC(object, -1);
        if ((short)destroy > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
