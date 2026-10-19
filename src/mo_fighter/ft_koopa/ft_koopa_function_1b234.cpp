#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_102_1B290(void*, short);

extern "C" void* fn_102_1B234(void* object, short deleting) {
    if (object != 0) {
        short baseDeleting = 0;
        fn_102_1B290(object, baseDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
