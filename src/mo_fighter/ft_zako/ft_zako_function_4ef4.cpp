#pragma force_active on
extern "C" void* fn_27_14B698(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_126_4EF4(void* object, int count) {
    if (object != 0) {
        fn_27_14B698(object, -1);
        if ((short)count > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
