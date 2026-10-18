#pragma force_active on
extern "C" void* fn_92_448C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_664C(void* object, int baseDeleting) {
    if (object != 0) {
        fn_92_448C(object, 0);
        if ((short)baseDeleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
