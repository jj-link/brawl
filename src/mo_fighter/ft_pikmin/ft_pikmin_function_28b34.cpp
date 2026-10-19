#pragma force_active on
extern "C" void fn_113_28BA4(void*, short);
extern "C" void fn_113_28E64(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_28B34(void* object, short deleting) {
    if (object != 0) {
        fn_113_28BA4(static_cast<unsigned char*>(object) + 0x1D44, -1);
        fn_113_28E64(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
