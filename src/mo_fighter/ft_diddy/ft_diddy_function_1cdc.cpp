#pragma force_active on
extern "C" void* fn_115_1B08(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_1CDC(void* object, int flag) {
    if (object != 0) {
        fn_115_1B08(object, 0);
        if ((short)flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
