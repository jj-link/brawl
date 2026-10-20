#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_122_3958(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_122_16F1C(void*, short);
void* fn_27_1D81C8(void*, short);
}

// Embedded members retain their storage; the base is destroyed non-deleting.
extern "C" void* fn_122_16E94(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_122_3958(members + 0x2398, memberDeleting);
        fn_27_1DBB60(members + 0x2360, memberDeleting);
        fn_122_16F1C(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
