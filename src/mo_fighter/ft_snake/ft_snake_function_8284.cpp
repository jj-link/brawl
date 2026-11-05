#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_122_3860(void*, short);
void* fn_122_3958(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_122_39B4(void*, short);
void* fn_122_2158(void*, short);
void* fn_122_21F4(void*, short);
void* fn_122_2234(void*, short);
void* fn_27_C7770(void*, short);
void* fn_122_7300(void*, short);
void* fn_122_3C20(void*, short);
void* fn_122_3C7C(void*, short);
void* fn_122_3D5C(void*, short);
void* fn_122_3DE8(void*, short);
void* fn_122_57B0(void*, short);
void* fn_122_6E70(void*, short);
void* fn_122_430C(void*, short);
void* fn_122_4440(void*, short);
void* fn_122_593C(void*, short);
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
void* fn_122_4AD0(void*, short);
void* fn_122_4B58(void*, short);
void* fn_122_4BC4(void*, short);
void* fn_122_4C7C(void*, short);
void* fn_122_4CBC(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_122_4D18(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_122_8284(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        if (members + 0x1F18 != 0) {
            if (members + 0x1F18 != 0) {
                fn_122_3860(members + 0x1F18, static_cast<short>(0));
            }
        }
        if (object != 0) {
            short memberDeleting = -1;
            fn_122_3958(members + 0x1ED0, memberDeleting);
            fn_27_1DBB60(members + 0x1E98, memberDeleting);
            if (members + 0xCC != 0) {
                if (members + 0x18E8 != 0) {
                    fn_122_39B4(members + 0x1D98, memberDeleting);
                    if (members + 0x1C6C != 0) {
                        fn_122_2158(members + 0x1D48, memberDeleting);
                        fn_122_21F4(members + 0x1D2C, memberDeleting);
                        fn_122_2234(members + 0x1C80, memberDeleting);
                        if (members + 0x1C6C != 0) {
                            fn_27_C7770(members + 0x1C6C, memberDeleting);
                        }
                    }
                    if (members + 0x1B40 != 0) {
                        short memberDeleting = -1;
                        fn_122_2158(members + 0x1C1C, memberDeleting);
                        fn_122_21F4(members + 0x1C00, memberDeleting);
                        fn_122_2234(members + 0x1B54, memberDeleting);
                        if (members + 0x1B40 != 0) {
                            fn_27_C7770(members + 0x1B40, memberDeleting);
                        }
                    }
                    if (members + 0x1A14 != 0) {
                        short memberDeleting = -1;
                        fn_122_2158(members + 0x1AF0, memberDeleting);
                        fn_122_21F4(members + 0x1AD4, memberDeleting);
                        fn_122_2234(members + 0x1A28, memberDeleting);
                        if (members + 0x1A14 != 0) {
                            fn_27_C7770(members + 0x1A14, memberDeleting);
                        }
                    }
                    fn_122_7300(members + 0x18E8, static_cast<short>(-1));
                }
                if (members + 0xCC != 0) {
                    short memberDeleting = -1;
                    fn_122_3C20(members + 0x18A4, memberDeleting);
                    fn_122_3C7C(members + 0x188C, memberDeleting);
                    fn_122_3D5C(members + 0x16F0, memberDeleting);
                    fn_122_3DE8(members + 0x1690, memberDeleting);
                    fn_122_57B0(members + 0x15DC, memberDeleting);
                    fn_122_6E70(members + 0x141C, memberDeleting);
                    fn_122_430C(members + 0x1378, memberDeleting);
                    fn_122_4440(members + 0x1344, memberDeleting);
                    fn_122_593C(members + 0x1310, memberDeleting);
                    fn_122_4558(members + 0x11AC, memberDeleting);
                    fn_122_45C4(members + 0x1144, memberDeleting);
                    fn_122_4624(members + 0x1138, memberDeleting);
                    fn_122_4684(members + 0x1110, memberDeleting);
                    fn_122_5998(members + 0xF40, memberDeleting);
                    fn_122_4850(members + 0xEDC, memberDeleting);
                    fn_122_491C(members + 0xEA0, memberDeleting);
                    fn_122_5B54(members + 0xDE8, memberDeleting);
                    if (members + 0xBDC != 0) {
                        fn_27_13C90(members + 0xC78, memberDeleting);
                        fn_27_21038(members + 0xC64, memberDeleting);
                        fn_122_4AD0(members + 0xBDC, memberDeleting);
                    }
                    short deleting2 = -1;
                    fn_122_4B58(members + 0x9FC, deleting2);
                    fn_122_4BC4(members + 0x9CC, deleting2);
                    fn_122_4C7C(members + 0x9BC, deleting2);
                    fn_122_4CBC(members + 0x9A4, deleting2);
                    __dt__16soModuleAccesserFv(members + 0x8C4, deleting2);
                    fn_122_4D18(members + 0xCC, deleting2);
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
