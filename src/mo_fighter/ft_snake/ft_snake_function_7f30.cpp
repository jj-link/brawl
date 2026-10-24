#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_122_3860(void*, short);
void* fn_122_3958(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_122_7270(void*, short);
void* fn_122_3C20(void*, short);
void* fn_122_3C7C(void*, short);
void* fn_122_3D5C(void*, short);
void* fn_122_3DE8(void*, short);
void* fn_122_57B0(void*, short);
void* fn_122_6E70(void*, short);
void* fn_122_430C(void*, short);
void* fn_122_4440(void*, short);
void* fn_122_767C(void*, short);
void* fn_122_44FC(void*, short);
void* fn_122_4558(void*, short);
void* fn_122_45C4(void*, short);
void* fn_122_4624(void*, short);
void* fn_122_4684(void*, short);
void* fn_122_5998(void*, short);
void* fn_122_4850(void*, short);
void* fn_122_491C(void*, short);
void* fn_122_5B54(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_27_19841C(void*, short);
void* fn_122_4AD0(void*, short);
void* fn_122_4B58(void*, short);
void* fn_122_4BC4(void*, short);
void* fn_122_4C7C(void*, short);
void* fn_122_4CBC(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_122_4D18(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_122_7F30(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        if (members + 0x1F84 != 0) {
            if (members + 0x1F84 != 0) {
                fn_122_3860(members + 0x1F84, static_cast<short>(0));
            }
        }
        if (object != 0) {
            short memberDeleting = -1;
            fn_122_3958(members + 0x1F3C, memberDeleting);
            fn_27_1DBB60(members + 0x1F04, memberDeleting);
            if (members + 0xCC != 0) {
                fn_122_7270(members + 0x1954, memberDeleting);
                if (members + 0xCC != 0) {
                    fn_122_3C20(members + 0x1910, memberDeleting);
                    fn_122_3C7C(members + 0x18F8, memberDeleting);
                    fn_122_3D5C(members + 0x175C, memberDeleting);
                    fn_122_3DE8(members + 0x16FC, memberDeleting);
                    fn_122_57B0(members + 0x1648, memberDeleting);
                    fn_122_6E70(members + 0x1488, memberDeleting);
                    fn_122_430C(members + 0x13E4, memberDeleting);
                    fn_122_4440(members + 0x13B0, memberDeleting);
                    fn_122_767C(members + 0x138C, memberDeleting);
                    fn_122_44FC(members + 0x1378, memberDeleting);
                    fn_122_4558(members + 0x1214, memberDeleting);
                    fn_122_45C4(members + 0x11AC, memberDeleting);
                    fn_122_4624(members + 0x11A0, memberDeleting);
                    fn_122_4684(members + 0x1178, memberDeleting);
                    fn_122_5998(members + 0xFA8, memberDeleting);
                    fn_122_4850(members + 0xF44, memberDeleting);
                    fn_122_491C(members + 0xF08, memberDeleting);
                    fn_122_5B54(members + 0xE50, memberDeleting);
                    if (members + 0xBDC != 0) {
                        fn_27_13C90(members + 0xCE0, memberDeleting);
                        fn_27_21038(members + 0xCCC, memberDeleting);
                        if (members + 0xC64 != 0) {
                            fn_27_19841C(members + 0xC64, memberDeleting);
                        }
                        fn_122_4AD0(members + 0xBDC, memberDeleting);
                    }
                    fn_122_4B58(members + 0x9FC, memberDeleting);
                    fn_122_4BC4(members + 0x9CC, memberDeleting);
                    fn_122_4C7C(members + 0x9BC, memberDeleting);
                    fn_122_4CBC(members + 0x9A4, memberDeleting);
                    __dt__16soModuleAccesserFv(members + 0x8C4, memberDeleting);
                    fn_122_4D18(members + 0xCC, memberDeleting);
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
