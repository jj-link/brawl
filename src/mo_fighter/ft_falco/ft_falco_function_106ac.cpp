#pragma force_active on
extern "C" void* fn_108_36C8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_106AC(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_108_36C8(object, baseDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
