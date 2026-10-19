#pragma force_active on
extern "C" void* fn_105_FACC(void* object, short deleting);
extern "C" void* __dl__FPv(void*);

extern "C" void* fn_105_FC64(void* object, short deleting) {
    if (object != 0) {
        short baseDeleting = 0;
        fn_105_FACC(object, baseDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
