#pragma force_active on
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_117_52E4(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = -1;
            fn_27_1A15B8(object, baseDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
