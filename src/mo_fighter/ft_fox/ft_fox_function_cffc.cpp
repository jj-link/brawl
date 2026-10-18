#pragma force_active on
extern "C" void* fn_97_CF9C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_CFFC(void* object, short deleting) {
    if (object != 0) {
        fn_97_CF9C(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
