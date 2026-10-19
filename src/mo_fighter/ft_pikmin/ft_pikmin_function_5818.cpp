#pragma force_active on
extern "C" void fn_27_1540CC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_5818(void* object, short release) {
    if (object != 0) {
        fn_27_1540CC(object, -1);
        if (release > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
