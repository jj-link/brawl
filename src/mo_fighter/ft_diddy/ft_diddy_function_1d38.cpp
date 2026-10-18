#pragma force_active on
extern "C" void fn_115_1B08(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_1D38(void* object, int shouldDelete) {
    if (object != 0) {
        fn_115_1B08(object, 0);
        if ((short)shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
