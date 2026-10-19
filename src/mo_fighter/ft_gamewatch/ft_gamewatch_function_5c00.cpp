#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_1F9CC(void*, short);
void* fn_107_3944(void*, short);
void* fn_107_3984(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_107_4F74(void*, short);
void* fn_107_3A8C(void*, short);
void* fn_107_3AE8(void*, short);
void* fn_107_3B44(void*, short);
void* fn_107_3BA0(void*, short);
void* fn_107_3C2C(void*, short);
void* fn_107_3D28(void*, short);
void* fn_107_512C(void*, short);
void* fn_107_40D0(void*, short);
void* fn_107_4204(void*, short);
void* fn_107_4260(void*, short);
void* fn_107_42BC(void*, short);
void* fn_107_4328(void*, short);
void* fn_107_4388(void*, short);
void* fn_107_43E8(void*, short);
void* fn_107_4444(void*, short);
void* fn_107_44C8(void*, short);
void* fn_107_4594(void*, short);
void* fn_107_465C(void*, short);
void* fn_107_51D0(void*, short);
void* fn_107_47B4(void*, short);
void* fn_107_4820(void*, short);
void* fn_107_48D8(void*, short);
void* fn_107_4918(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_107_4974(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_107_5C00(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_27_1F9CC(members + 0x20B8, static_cast<short>(-1));

        if (members + 0x208C != 0) {
            if (members + 0x208C != 0) {
                fn_107_3944(members + 0x208C, static_cast<short>(0));
            }
        }

        if (object != 0) {
            short memberDeleting = -1;
            fn_107_3984(members + 0x2044, memberDeleting);
            fn_27_1DBB60(members + 0x200C, memberDeleting);

            if (members + 0xCC != 0) {
                fn_107_4F74(members + 0x1A5C, memberDeleting);
                if (members + 0xCC != 0) {
                    fn_107_3A8C(members + 0x1A18, memberDeleting);
                    fn_107_3AE8(members + 0x1A00, memberDeleting);
                    fn_107_3B44(members + 0x18A8, memberDeleting);
                    fn_107_3BA0(members + 0x1710, memberDeleting);
                    fn_107_3C2C(members + 0x16B0, memberDeleting);
                    fn_107_3D28(members + 0x15FC, memberDeleting);
                    fn_107_512C(members + 0x143C, memberDeleting);
                    fn_107_40D0(members + 0x1398, memberDeleting);
                    fn_107_4204(members + 0x1364, memberDeleting);
                    fn_107_4260(members + 0x134C, memberDeleting);
                    fn_107_42BC(members + 0x11E8, memberDeleting);
                    fn_107_4328(members + 0x1180, memberDeleting);
                    fn_107_4388(members + 0x1174, memberDeleting);
                    fn_107_43E8(members + 0x114C, memberDeleting);
                    fn_107_4444(members + 0xF7C, memberDeleting);
                    fn_107_44C8(members + 0xF18, memberDeleting);
                    fn_107_4594(members + 0xEDC, memberDeleting);
                    fn_107_465C(members + 0xE24, memberDeleting);
                    fn_107_51D0(members + 0xBDC, memberDeleting);
                    fn_107_47B4(members + 0x9FC, memberDeleting);
                    fn_107_4820(members + 0x9CC, memberDeleting);
                    fn_107_48D8(members + 0x9BC, memberDeleting);
                    fn_107_4918(members + 0x9A4, memberDeleting);
                    __dt__16soModuleAccesserFv(members + 0x8C4, memberDeleting);
                    fn_107_4974(members + 0xCC, memberDeleting);
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
