#pragma force_active on
extern "C" void fn_27_1540CC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_6010(void* object, int flag) {
    if (object != 0) {
        fn_27_1540CC(object, static_cast<short>(-1));
        if (static_cast<short>(flag) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
