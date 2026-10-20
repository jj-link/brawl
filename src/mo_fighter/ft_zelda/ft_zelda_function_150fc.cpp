#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_104_3844(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_104_15184(void*, short);
void* fn_27_1D81C8(void*, short);
}

// Embedded members retain their storage; the base is destroyed non-deleting.
extern "C" void* fn_104_150FC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_104_3844(members + 0x1ED0, memberDeleting);
        fn_27_1DBB60(members + 0x1E98, memberDeleting);
        fn_104_15184(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
