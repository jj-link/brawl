#pragma force_active on
extern "C" void* fn_27_1A1FE4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_683C(void* object, short memberDeleteFlag) {
    if (object != 0) {
        if (object != 0) {
            fn_27_1A1FE4(object, -1);
        }
        if (memberDeleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
