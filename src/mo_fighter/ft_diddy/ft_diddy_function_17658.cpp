#pragma force_active on
extern "C" void* fn_115_A230(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_17658(void* object, short baseDeleting) {
    if (object != 0) {
        fn_115_A230(object, 0);
        if (baseDeleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
