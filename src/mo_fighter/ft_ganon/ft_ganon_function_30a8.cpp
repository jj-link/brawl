#pragma force_active on
extern "C" void* fn_27_A0C34(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_30A8(void* object, int p2) {
    if (object != 0) {
        fn_27_A0C34(object, -1);
        if ((short)p2 > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
