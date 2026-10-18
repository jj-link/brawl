#pragma force_active on
extern "C" void* fn_115_A230(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_1AA44(void* object, int baseDeleting) {
    if (object != 0) {
        fn_115_A230(object, 0);
        if ((short)baseDeleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
