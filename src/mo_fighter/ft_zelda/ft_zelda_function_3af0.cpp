#pragma force_active on
extern "C" void* fn_27_C31CC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_3AF0(void* object, short deleting) {
    if (object != 0) {
        fn_27_C31CC(object, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
