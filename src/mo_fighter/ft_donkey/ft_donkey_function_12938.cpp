#pragma force_active on
extern "C" void* fn_92_4F04(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_12938(void* object, int destroy) {
    if (object != 0) {
        fn_92_4F04(object, 0);
        if ((short)destroy > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
