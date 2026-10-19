#pragma force_active on
extern "C" void fn_94_4BB4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_6504(void* object, short deleting) {
    if (object != 0) {
        short baseDeleting = 0;
        fn_94_4BB4(object, baseDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
