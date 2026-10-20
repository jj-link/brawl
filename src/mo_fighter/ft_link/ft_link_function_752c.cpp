#pragma force_active on
extern "C" void fn_93_74CC(void* object, short deleting);
extern "C" void* fn_93_6BF0(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_752C(void* object, short deleting) {
    if (object != 0) {
        fn_93_74CC(static_cast<unsigned char*>(object) + 0x2DAC, -1);
        if (object != 0) {
            fn_93_6BF0(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
