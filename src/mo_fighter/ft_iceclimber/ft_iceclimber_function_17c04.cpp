#pragma force_active on
extern "C" void* fn_105_45E4(void* ptr, short size);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_17C04(void* object, short deleting) {
    if (object != 0) {
        short baseDeleting = 0;
        fn_105_45E4(object, baseDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
