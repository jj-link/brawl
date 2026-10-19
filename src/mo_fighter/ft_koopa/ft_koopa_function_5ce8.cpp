#pragma force_active on
extern "C" void* fn_102_5D44(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_5CE8(void* object, short deleting) {
    if (object) {
        fn_102_5D44(object, 0);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
