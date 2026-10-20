#pragma force_active on
extern "C" void* fn_108_D000(void*, short);
extern "C" void* fn_108_CECC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_D060(void* object, short deleting) {
    if (object != 0) {
        fn_108_D000(static_cast<unsigned char*>(object) + 0x134, -1);
        if (object != 0) {
            fn_108_CECC(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
