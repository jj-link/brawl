#pragma force_active on
extern "C" void* fn_27_5C674(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_3AD4(void* object, int flag) {
    if (object != 0) {
        fn_27_5C674(object, -1);
        if ((short)flag > 0)
            __dl__FPv(object);
    }
    return object;
}
