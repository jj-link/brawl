#pragma force_active on
extern "C" void* fn_102_1AA9C(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_1AA40(void* object, short deleting) {
    if (object != 0) {
        fn_102_1AA9C(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
