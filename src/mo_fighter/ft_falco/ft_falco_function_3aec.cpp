#pragma force_active on

extern "C" void* fn_108_3B48(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_3AEC(void* object, int flag) {
    if (object != 0) {
        fn_108_3B48(object, 0);
        if ((short)flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
