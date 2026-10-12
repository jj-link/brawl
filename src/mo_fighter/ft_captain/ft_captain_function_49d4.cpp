void operator delete(void*);

extern "C" {
void* fn_100_37BC(void*, short);
void* fn_100_37FC(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_100_3898(void*, short);
void* fn_100_2158(void*, short);
void* fn_100_21F4(void*, short);
void* fn_100_2234(void*, short);
void* fn_27_C7770(void*, short);
void* fn_100_3904(void*, short);
void* fn_100_3960(void*, short);
void* fn_100_39BC(void*, short);
void* fn_100_3A48(void*, short);
void* fn_100_3B44(void*, short);
void* fn_100_3C80(void*, short);
void* fn_100_3D04(void*, short);
void* fn_27_1A2D10(void*, short);
void* fn_100_3D64(void*, short);
void* fn_100_3E8C(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_100_3EEC(void*, short);
void* fn_100_4020(void*, short);
void* fn_100_407C(void*, short);
void* fn_100_40D8(void*, short);
void* fn_100_4144(void*, short);
void* fn_100_41A4(void*, short);
void* fn_100_4204(void*, short);
void* fn_100_4260(void*, short);
void* fn_100_42E4(void*, short);
void* fn_100_43B0(void*, short);
void* fn_100_440C(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_100_44DC(void*, short);
void* fn_100_4564(void*, short);
void* fn_100_45D0(void*, short);
void* fn_100_4688(void*, short);
void* fn_100_46C8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_100_4724(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_100_49D4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        // The receiver checks delimit distinct inlined member/base destructors.
        // Members release their resources, but not the aggregate's storage.
        if (members + 0x1EFC != 0) {
            fn_100_37BC(members + 0x1EFC, static_cast<short>(0));
        }
        if (object != 0) {
            short memberDeleting = -1;
            fn_100_37FC(members + 0x1EB4, memberDeleting);
            fn_27_1DBB60(members + 0x1E7C, memberDeleting);
            if (members + 0xCC != 0) {
                if (members + 0x18CC != 0) {
                    fn_100_3898(members + 0x1D7C, memberDeleting);
                    if (members + 0x1C50 != 0) {
                        fn_100_2158(members + 0x1D2C, memberDeleting);
                        fn_100_21F4(members + 0x1D10, memberDeleting);
                        fn_100_2234(members + 0x1C64, memberDeleting);
                        if (members + 0x1C50 != 0) {
                            fn_27_C7770(members + 0x1C50, memberDeleting);
                        }
                    }
                    if (members + 0x1B24 != 0) {
                        fn_100_2158(members + 0x1C00, memberDeleting);
                        fn_100_21F4(members + 0x1BE4, memberDeleting);
                        fn_100_2234(members + 0x1B38, memberDeleting);
                        if (members + 0x1B24 != 0) {
                            fn_27_C7770(members + 0x1B24, memberDeleting);
                        }
                    }
                    if (members + 0x19F8 != 0) {
                        fn_100_2158(members + 0x1AD4, memberDeleting);
                        fn_100_21F4(members + 0x1AB8, memberDeleting);
                        fn_100_2234(members + 0x1A0C, memberDeleting);
                        if (members + 0x19F8 != 0) {
                            fn_27_C7770(members + 0x19F8, memberDeleting);
                        }
                    }
                    if (members + 0x18CC != 0) {
                        fn_100_2158(members + 0x19A8, memberDeleting);
                        fn_100_21F4(members + 0x198C, memberDeleting);
                        fn_100_2234(members + 0x18E0, memberDeleting);
                        if (members + 0x18CC != 0) {
                            fn_27_C7770(members + 0x18CC, memberDeleting);
                        }
                    }
                }
                if (members + 0xCC != 0) {
                    fn_100_3904(members + 0x1888, memberDeleting);
                    fn_100_3960(members + 0x1870, memberDeleting);
                    fn_100_39BC(members + 0x16D4, memberDeleting);
                    fn_100_3A48(members + 0x1674, memberDeleting);
                    fn_100_3B44(members + 0x15C0, memberDeleting);
                    if (members + 0x1400 != 0) {
                        fn_100_3C80(members + 0x1510, memberDeleting);
                        fn_100_3D04(members + 0x14FC, memberDeleting);
                        if (members + 0x14EC != 0) {
                            fn_27_1A2D10(members + 0x14EC, memberDeleting);
                        }
                        fn_100_3D64(members + 0x1448, memberDeleting);
                        fn_100_3E8C(members + 0x1410, memberDeleting);
                        fn_27_C74E8(members + 0x1400, memberDeleting);
                    }
                    fn_100_3EEC(members + 0x135C, memberDeleting);
                    fn_100_4020(members + 0x1328, memberDeleting);
                    fn_100_407C(members + 0x1310, memberDeleting);
                    fn_100_40D8(members + 0x11AC, memberDeleting);
                    fn_100_4144(members + 0x1144, memberDeleting);
                    fn_100_41A4(members + 0x1138, memberDeleting);
                    fn_100_4204(members + 0x1110, memberDeleting);
                    fn_100_4260(members + 0xF40, memberDeleting);
                    fn_100_42E4(members + 0xEDC, memberDeleting);
                    fn_100_43B0(members + 0xEA0, memberDeleting);
                    fn_100_440C(members + 0xDE8, memberDeleting);
                    if (members + 0xBDC != 0) {
                        fn_27_13C90(members + 0xC78, memberDeleting);
                        fn_27_21038(members + 0xC64, memberDeleting);
                        fn_100_44DC(members + 0xBDC, memberDeleting);
                    }
                    fn_100_4564(members + 0x9FC, memberDeleting);
                    fn_100_45D0(members + 0x9CC, memberDeleting);
                    fn_100_4688(members + 0x9BC, memberDeleting);
                    fn_100_46C8(members + 0x9A4, memberDeleting);
                    __dt__16soModuleAccesserFv(members + 0x8C4, memberDeleting);
                    fn_100_4724(members + 0xCC, memberDeleting);
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
