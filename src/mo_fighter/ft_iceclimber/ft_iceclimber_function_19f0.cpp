#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_105_1AA8(void*, short);
void* fn_105_1B68(void*, short);
void* fn_105_1BC4(void*, short);
void* fn_105_1C20(void*, short);
void* fn_105_1C7C(void*, short);
void* fn_105_1CD8(void*, short);
void* fn_105_1D34(void*, short);
void* fn_105_1D90(void*, short);
}

extern "C" void* fn_105_19F0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_105_1AA8(members + 0x84, memberDeleting);
        fn_105_1B68(members + 0x70, memberDeleting);
        fn_105_1BC4(members + 0x5C, memberDeleting);
        fn_105_1C20(members + 0x48, memberDeleting);
        fn_105_1C7C(members + 0x34, memberDeleting);
        fn_105_1CD8(members + 0x20, memberDeleting);
        fn_105_1D34(members + 0x08, memberDeleting);
        fn_105_1D90(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
