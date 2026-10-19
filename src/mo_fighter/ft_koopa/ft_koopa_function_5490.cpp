#pragma force_active on
extern "C" void fn_27_1540CC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_5490(void* object, short param) {
    if (object != 0) {
        fn_27_1540CC(object, -1);
        if (param > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
