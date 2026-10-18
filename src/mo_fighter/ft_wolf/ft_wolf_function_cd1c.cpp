#pragma force_active on
extern "C" void* fn_125_CCBC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_CD1C(void* object, short deleting) {
    if (object != 0) {
        fn_125_CCBC(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
