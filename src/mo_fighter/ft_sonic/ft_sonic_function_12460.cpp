#pragma force_active on
extern "C" {
void* fn_123_124E8(void* ptr, short baseDeleting);
void* fn_27_1DBB60(void*, short);
void* fn_123_12544(void* object, short deleting);
void* fn_27_1D81C8(void* self, short flag);
}

// Embedded members retain their storage; the base is destroyed non-deleting.
extern "C" void* fn_123_12460(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_123_124E8(members + 0x2114, memberDeleting);
        fn_27_1DBB60(members + 0x20dc, memberDeleting);
        fn_123_12544(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
