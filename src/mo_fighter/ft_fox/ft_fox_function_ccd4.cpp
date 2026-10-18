#pragma force_active on
extern "C" void fn_97_CC74(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_CCD4(void* object, short deleting) {
    if (object != 0) {
        fn_97_CC74(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
