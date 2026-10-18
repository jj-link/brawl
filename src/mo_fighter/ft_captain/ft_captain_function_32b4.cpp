#pragma force_active on
extern "C" void fn_100_3310(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_32B4(void* object, int shouldDelete) {
    if (object != 0) {
        fn_100_3310(object, 0);
        if ((short)shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
