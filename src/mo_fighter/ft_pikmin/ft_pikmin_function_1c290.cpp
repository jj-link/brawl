#pragma force_active on
extern "C" void* fn_113_4730(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_1C290(void* object, short deleting) {
    if (object != 0) {
        short baseDeleting = 0;
        fn_113_4730(object, baseDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
