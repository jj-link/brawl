#pragma force_active on
extern "C" void* fn_27_C21DC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_2D18(void* object, short deleteFlag) {
    if (object != 0) {
        fn_27_C21DC(object, -1);
        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
