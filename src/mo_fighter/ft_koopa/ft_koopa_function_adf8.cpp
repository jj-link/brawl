#pragma force_active on
extern "C" void* fn_102_3A4C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_ADF8(void* object, short deleting) {
    if (object != 0) {
        short baseDeleting = 0;
        fn_102_3A4C(object, baseDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
