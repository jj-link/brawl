#pragma force_active on
extern "C" void* fn_117_13B28(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_117_13BC4(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_117_13B28(object, baseDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
