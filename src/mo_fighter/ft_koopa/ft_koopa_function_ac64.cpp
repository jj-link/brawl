#pragma force_active on
extern "C" void fn_102_3A4C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_AC64(void* object, short deleting) {
    if (object != 0) {
        fn_102_3A4C(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
