void operator delete(void*);
extern "C" {
void* fn_101_3BA8(void*, short);
void* fn_101_57F0(void*, short);
void* fn_101_587C(void*, short);
void* fn_101_5908(void*, short);
void* fn_101_23D8(void*, short);
void* fn_101_2474(void*, short);
void* fn_101_24B4(void*, short);
void* fn_27_C7770(void*, short);
}

// Embedded-member cleanup layer shared by the fighter module destructors:
// releases the four upper member regions, then the guarded lower group and
// the module-27 lifetime receiver, and deletes the storage when requested.
extern "C" void* fn_101_572C(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_101_3BA8(static_cast<unsigned char*>(object) + 0x4B0, memberDeleting);
        fn_101_57F0(static_cast<unsigned char*>(object) + 0x384, memberDeleting);
        fn_101_587C(static_cast<unsigned char*>(object) + 0x258, memberDeleting);
        fn_101_5908(static_cast<unsigned char*>(object) + 0x12C, memberDeleting);
        if (object != 0) {
            fn_101_23D8(static_cast<unsigned char*>(object) + 0xDC, memberDeleting);
            fn_101_2474(static_cast<unsigned char*>(object) + 0xC0, memberDeleting);
            fn_101_24B4(static_cast<unsigned char*>(object) + 0x14, memberDeleting);
            if (object != 0) {
                fn_27_C7770(object, memberDeleting);
            }
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
