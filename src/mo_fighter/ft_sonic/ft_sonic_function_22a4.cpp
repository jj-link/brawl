#pragma force_active on
extern "C" void* fn_123_2310(void*, short);
extern "C" void* fn_123_216C(void*, short);
extern "C" void __dl__FPv(void*);

// Release the embedded member before the base, retaining their storage.
extern "C" void* fn_123_22A4(void* object, short deleting) {
    if (object != 0) {
        fn_123_2310(static_cast<unsigned char*>(object) + 0x50, -1);
        fn_123_216C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
