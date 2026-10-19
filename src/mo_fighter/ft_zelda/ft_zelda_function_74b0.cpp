#pragma force_active on
extern "C" void* fn_104_750C(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_74B0(void* object, short deleting) {
    if (object != 0) {
        fn_104_750C(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
