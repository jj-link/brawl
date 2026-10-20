#pragma force_active on
extern "C" {
void* fn_105_36B4(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_105_1E2AC(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_105_1E224(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_105_36B4(members + 0x2098, memberDeleting);
        fn_27_1DBB60(members + 0x2060, memberDeleting);
        fn_105_1E2AC(members + 0xCC, memberDeleting);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
