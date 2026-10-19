#pragma force_active on
extern "C" void* fn_104_11A20(void*, short);
extern "C" void* fn_104_11B3C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_119B0(void* object, short deleting) {
    if (object != 0) {
        // Destroy the embedded aggregate first (with deleting = -1), then the
        // non-deleting destructor form on the object itself.
        fn_104_11A20(static_cast<unsigned char*>(object) + 0x1984, -1);
        fn_104_11B3C(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
