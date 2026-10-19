#pragma force_active on
extern "C" void* fn_96_11CE8(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_11E80(void* object, short deleting) {
    if (object != 0) {
        short baseDeleting = 0;
        fn_96_11CE8(object, baseDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
