#pragma force_active on
extern "C" void fn_112_C3B8(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_C550(void* object, short deleting) {
    if (object != 0) {
        fn_112_C3B8(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
