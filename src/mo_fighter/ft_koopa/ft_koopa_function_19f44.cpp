#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_102_19FCC(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_102_1A028(void*, short);
void* fn_27_1D81C8(void*, short);
}

// Embedded members retain their storage; the base is destroyed non-deleting.
extern "C" void* fn_102_19F44(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_102_19FCC(members + 0x1F38, memberDeleting);
        fn_27_1DBB60(members + 0x1F00, memberDeleting);
        fn_102_1A028(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
