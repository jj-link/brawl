#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_107_3984(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_107_1C7D8(void*, short);
void* fn_27_1D81C8(void*, short);
}

// Embedded members retain their storage; the base is destroyed non-deleting.
extern "C" void* fn_107_1C750(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_107_3984(members + 0x2044, memberDeleting);
        fn_27_1DBB60(members + 0x200c, memberDeleting);
        fn_107_1C7D8(members + 0xcc, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
