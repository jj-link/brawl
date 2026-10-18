#pragma force_active on
extern "C" void* fn_115_15344(void* ptr, short count);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_115_15384(void* object, short baseDeleting) {
    if (object != 0) {
        fn_115_15344(object, 0);
        if (baseDeleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
