#pragma force_active on
extern "C" void* fn_115_A230(void* ptr, short flag);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_115_BD14(void* object, short baseDeleting) {
    if (object != 0) {
        fn_115_A230(object, 0);
        if (baseDeleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
