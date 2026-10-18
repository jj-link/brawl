#pragma force_active on
extern "C" void fn_27_3544C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_4408(void* object, int flag) {
    if (object != 0) {
        fn_27_3544C(object, -1);
        if ((short)flag > 0)
            __dl__FPv(object);
    }
    return object;
}
