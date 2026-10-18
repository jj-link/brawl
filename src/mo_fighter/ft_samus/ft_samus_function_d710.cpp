#pragma force_active on
extern "C" void fn_94_4750(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_D710(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_94_4750(object, baseDeleting);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
