#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_96_88E8(void*, short);
void* fn_96_8460(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_96_8928(void*, short);
void* fn_96_8A88(void*, short);
void* fn_96_7C18(void*, short);
void* fn_96_6C08(void*, short);
void* fn_96_6C64(void*, short);
void* fn_96_2874(void*, short);
void* fn_96_7C74(void*, short);
void* fn_96_6D1C(void*, short);
void* fn_96_8AE4(void*, short);
void* fn_96_8B78(void*, short);
void* fn_96_6D7C(void*, short);
void* fn_96_27B8(void*, short);
void* fn_27_5B39C(void*, short);
void* fn_96_6E60(void*, short);
void* fn_96_7DE4(void*, short);
void* fn_96_6ECC(void*, short);
void* fn_96_7E44(void*, short);
void* fn_96_8C7C(void*, short);
void* fn_96_6F2C(void*, short);
void* fn_96_259C(void*, short);
void* fn_96_24BC(void*, short);
void* fn_96_8D00(void*, short);
void* fn_96_7040(void*, short);
void* fn_96_70AC(void*, short);
void* fn_96_7124(void*, short);
void* fn_96_2460(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_96_7F18(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_96_86E4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        if (members + 0x20D0 != 0) {
            if (members + 0x20D0 != 0) {
                fn_96_88E8(members + 0x20D0, static_cast<short>(0));
            }
        }
        if (object != 0) {
            short memberDeleting = -1;
            fn_96_8460(members + 0x2088, memberDeleting);
            fn_27_1DBB60(members + 0x2050, memberDeleting);
            if (members + 0xCC != 0) {
                fn_96_8928(members + 0x1AA0, memberDeleting);
                if (members + 0xCC != 0) {
                    fn_96_8A88(members + 0x1A84, memberDeleting);
                    fn_96_7C18(members + 0x1A44, memberDeleting);
                    fn_96_6C08(members + 0x1A2C, memberDeleting);
                    fn_96_6C64(members + 0x18D4, memberDeleting);
                    fn_96_2874(members + 0x1888, memberDeleting);
                    fn_96_7C74(members + 0x16F0, memberDeleting);
                    fn_96_6D1C(members + 0x1690, memberDeleting);
                    fn_96_8AE4(members + 0x15DC, memberDeleting);
                    fn_96_8B78(members + 0x141C, memberDeleting);
                    fn_96_6D7C(members + 0x1378, memberDeleting);
                    fn_96_27B8(members + 0x1344, memberDeleting);
                    if (members + 0x1310 != 0) {
                        fn_27_5B39C(members + 0x1310, memberDeleting);
                    }
                    fn_96_6E60(members + 0x11AC, memberDeleting);
                    fn_96_7DE4(members + 0x1144, memberDeleting);
                    fn_96_6ECC(members + 0x1138, memberDeleting);
                    fn_96_7E44(members + 0x1110, memberDeleting);
                    fn_96_8C7C(members + 0xF40, memberDeleting);
                    fn_96_6F2C(members + 0xEDC, memberDeleting);
                    fn_96_259C(members + 0xEA0, memberDeleting);
                    fn_96_24BC(members + 0xDE8, memberDeleting);
                    fn_96_8D00(members + 0xBDC, memberDeleting);
                    fn_96_7040(members + 0x9FC, memberDeleting);
                    fn_96_70AC(members + 0x9CC, memberDeleting);
                    fn_96_7124(members + 0x9BC, memberDeleting);
                    fn_96_2460(members + 0x9A4, memberDeleting);
                    __dt__16soModuleAccesserFv(members + 0x8C4, memberDeleting);
                    fn_96_7F18(members + 0xCC, memberDeleting);
                }
            }
            fn_27_1D81C8(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
