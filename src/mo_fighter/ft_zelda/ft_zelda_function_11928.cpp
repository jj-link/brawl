#pragma force_active on
extern "C" void* fn_104_3844(void*, short);
extern "C" void* fn_27_1DBB60(void*, short);
extern "C" void* fn_104_119B0(void*, short);
extern "C" void* fn_27_1D81C8(void*, short);
extern "C" void operator delete(void*);

// Embedded members retain their storage; the base is destroyed non-deleting.
extern "C" void* fn_104_11928(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_104_3844(members + 0x2038, memberDeleting);
        fn_27_1DBB60(members + 0x2000, memberDeleting);
        fn_104_119B0(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
