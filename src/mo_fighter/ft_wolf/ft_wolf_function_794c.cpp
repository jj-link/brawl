#pragma force_active on
extern "C" void* fn_125_42F0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_794C(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_125_42F0(object, baseDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
