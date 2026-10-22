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
void* fn_96_7C74(void*, short);
void* fn_96_6D1C(void*, short);
void* fn_96_8AE4(void*, short);
void* fn_96_8B78(void*, short);
void* fn_96_6D7C(void*, short);
void* fn_96_27B8(void*, short);
void* fn_96_6E60(void*, short);
void* fn_96_7DE4(void*, short);
void* fn_96_6ECC(void*, short);
void* fn_96_7E44(void*, short);
void* fn_96_8C7C(void*, short);
void* fn_96_6F2C(void*, short);
void* fn_96_259C(void*, short);
void* fn_96_2530(void*, short);
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

extern "C" void* fn_96_8FF0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        if (members + 0x1FA4 != 0) {
            if (members + 0x1FA4 != 0) {
                fn_96_88E8(members + 0x1FA4, static_cast<short>(0));
            }
        }
        if (object != 0) {
            short memberDeleting = -1;
            fn_96_8460(members + 0x1F5C, memberDeleting);
            fn_27_1DBB60(members + 0x1F24, memberDeleting);
            if (members + 0xCC != 0) {
                fn_96_8928(members + 0x1974, memberDeleting);
                if (members + 0xCC != 0) {
                    fn_96_8A88(members + 0x1958, memberDeleting);
                    fn_96_7C18(members + 0x1918, memberDeleting);
                    fn_96_6C08(members + 0x1900, memberDeleting);
                    fn_96_7C74(members + 0x1764, memberDeleting);
                    fn_96_6D1C(members + 0x1704, memberDeleting);
                    fn_96_8AE4(members + 0x1650, memberDeleting);
                    fn_96_8B78(members + 0x1490, memberDeleting);
                    fn_96_6D7C(members + 0x13EC, memberDeleting);
                    fn_96_27B8(members + 0x13B8, memberDeleting);
                    fn_96_6E60(members + 0x1250, memberDeleting);
                    fn_96_7DE4(members + 0x11E8, memberDeleting);
                    fn_96_6ECC(members + 0x11DC, memberDeleting);
                    fn_96_7E44(members + 0x11B4, memberDeleting);
                    fn_96_8C7C(members + 0xFE4, memberDeleting);
                    fn_96_6F2C(members + 0xF80, memberDeleting);
                    fn_96_259C(members + 0xF44, memberDeleting);
                    fn_96_2530(members + 0xE9C, memberDeleting);
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
