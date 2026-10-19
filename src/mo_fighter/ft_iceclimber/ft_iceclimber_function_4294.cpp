#pragma force_active on
extern "C" void* fn_27_A1E80(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_4294(void* object, short deleting) {
    if (object != 0) {
        fn_27_A1E80(object, -1);
        if ((short)deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
