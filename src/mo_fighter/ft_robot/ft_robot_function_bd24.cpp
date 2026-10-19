#pragma force_active on
extern "C" void fn_120_BCAC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_BD24(void* object, short deleting) {
    if (object != 0) {
        fn_120_BCAC(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
