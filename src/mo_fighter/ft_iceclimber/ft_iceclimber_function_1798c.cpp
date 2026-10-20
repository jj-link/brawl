#pragma force_active on
extern "C" {
void* fn_105_36B4(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_105_17A14(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_105_1798C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_105_36B4(members + 0x1ECC, memberDeleting);
        fn_27_1DBB60(members + 0x1E94, memberDeleting);
        fn_105_17A14(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
