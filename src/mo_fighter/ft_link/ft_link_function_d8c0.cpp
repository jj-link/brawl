#pragma force_active on
extern "C" void fn_93_7100(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_D8C0(void* object, short deleting) {
    if (object) {
        short baseDeleting = 0;
        fn_93_7100(object, baseDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
