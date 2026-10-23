#pragma force_active on
extern "C" {
void* fn_106_1AA0(void*, short);
void* fn_106_1B60(void*, short);
void* fn_106_1BBC(void*, short);
void* fn_106_1C18(void*, short);
void* fn_106_1C74(void*, short);
void* fn_106_1CD0(void*, short);
void* fn_106_1D2C(void*, short);
void* fn_106_1D88(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_106_19E8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_106_1AA0(members + 0x84, memberDeleting);
        fn_106_1B60(members + 0x70, memberDeleting);
        fn_106_1BBC(members + 0x5C, memberDeleting);
        fn_106_1C18(members + 0x48, memberDeleting);
        fn_106_1C74(members + 0x34, memberDeleting);
        fn_106_1CD0(members + 0x20, memberDeleting);
        fn_106_1D2C(members + 8, memberDeleting);
        fn_106_1D88(object, static_cast<short>(0));
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
