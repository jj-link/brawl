#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_93_12A18(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_93_13750(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_93_137C0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_93_12A18(members + 0x20A0, memberDeleting);
        fn_27_1DBB60(members + 0x2068, memberDeleting);
        fn_93_13750(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
