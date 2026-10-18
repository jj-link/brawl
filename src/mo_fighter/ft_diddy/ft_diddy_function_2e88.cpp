#pragma force_active on
extern "C" void* fn_27_ACC5C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_2E88(void* object, int flag) {
    if (object != 0) {
        fn_27_ACC5C(object, -1);
        if ((short)flag > 0)
            __dl__FPv(object);
    }
    return object;
}
