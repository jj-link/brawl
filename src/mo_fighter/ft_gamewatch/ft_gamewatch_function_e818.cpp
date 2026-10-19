#pragma force_active on
extern "C" void* fn_107_E680(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_E818(void* object, short deleting) {
    if (object != 0) {
        short baseDeleting = 0;
        fn_107_E680(object, baseDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
