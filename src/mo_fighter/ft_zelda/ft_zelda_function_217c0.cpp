#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_104_3844(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_104_21848(void*, short);
void* fn_27_1D81C8(void*, short);
void __dl__FPv(void*);
}

// Embedded members retain their storage; the base is destroyed non-deleting.
extern "C" void* fn_104_217C0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_104_3844(members + 0x1ECC, memberDeleting);
        fn_27_1DBB60(members + 0x1E94, memberDeleting);
        fn_104_21848(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
