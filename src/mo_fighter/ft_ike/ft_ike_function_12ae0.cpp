#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_119_11484(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_119_12A70(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_119_12AE0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_119_11484(members + 0x228C, memberDeleting);
        fn_27_1DBB60(members + 0x2254, memberDeleting);
        fn_119_12A70(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
