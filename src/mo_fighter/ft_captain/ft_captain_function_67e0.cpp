#pragma force_active on
extern "C" void* fn_100_683C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_67E0(void* object, short memberDeleteFlag) {
    if (object != 0) {
        fn_100_683C(object, 0);
        if (memberDeleteFlag > 0)
            __dl__FPv(object);
    }
    return object;
}
