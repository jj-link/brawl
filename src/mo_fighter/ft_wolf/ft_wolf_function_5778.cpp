#pragma force_active on
extern "C" void fn_125_57D8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_5778(void* object, short deleting) {
    if (object != 0) {
        fn_125_57D8(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
