#pragma force_active on
extern "C" void* fn_123_1ECC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_3CD8(void* object, short deleting) {
    if (object != 0) {
        fn_123_1ECC(static_cast<unsigned char*>(object) + 8, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
