#pragma force_active on
extern "C" void* fn_120_B538(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_B6D0(void* object, short deleting) {
    if (object != 0) {
        fn_120_B538(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
