#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_125_3720(void*, short);
void* fn_125_3760(void*, short);
void* fn_125_37CC(void*, short);
void* fn_125_3858(void*, short);
void* fn_125_38E4(void*, short);
void* fn_125_220C(void*, short);
void* fn_125_22A8(void*, short);
void* fn_125_22E8(void*, short);
void* fn_27_C7770(void*, short);
void* fn_125_4D18(void*, short);
void* fn_125_39FC(void*, short);
void* fn_125_3A58(void*, short);
void* fn_125_3AE4(void*, short);
void* fn_125_3C84(void*, short);
void* fn_125_3D08(void*, short);
void* fn_27_1A405C(void*, short);
void* fn_125_3D68(void*, short);
void* fn_125_3E90(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_125_3EF0(void*, short);
void* fn_125_4024(void*, short);
void* fn_125_4080(void*, short);
void* fn_125_40DC(void*, short);
void* fn_125_4148(void*, short);
void* fn_125_41A8(void*, short);
void* fn_125_4208(void*, short);
void* fn_125_5570(void*, short);
void* fn_125_4264(void*, short);
void* fn_125_4330(void*, short);
void* fn_125_438C(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_125_445C(void*, short);
void* fn_125_44E4(void*, short);
void* fn_125_4550(void*, short);
void* fn_125_4608(void*, short);
void* fn_125_4648(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_125_46A4(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_125_52DC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        if (members + 0x1DB4 != 0) {
            if (members + 0x1DB4 != 0) {
                fn_125_3720(members + 0x1DB4, static_cast<short>(0));
            }
        }
        if (object != 0) {
            short memberDeleting = -1;
            if (members + 0xCC != 0) {
                if (members + 0x17FC != 0) {
                    fn_125_3760(members + 0x1CAC, memberDeleting);
                    fn_125_37CC(members + 0x1B80, memberDeleting);
                    fn_125_3858(members + 0x1A54, memberDeleting);
                    fn_125_38E4(members + 0x1928, memberDeleting);
                    if (members + 0x17FC != 0) {
                        fn_125_220C(members + 0x18D8, memberDeleting);
                        fn_125_22A8(members + 0x18BC, memberDeleting);
                        fn_125_22E8(members + 0x1810, memberDeleting);
                        if (members + 0x17FC != 0) {
                            fn_27_C7770(members + 0x17FC, memberDeleting);
                        }
                    }
                }
                if (members + 0xCC != 0) {
                    fn_125_4D18(members + 0x17E0, memberDeleting);
                    fn_125_39FC(members + 0x17C4, memberDeleting);
                    fn_125_3A58(members + 0x1628, memberDeleting);
                    fn_125_3AE4(members + 0x15C8, memberDeleting);
                    if (members + 0x1400 != 0) {
                        fn_125_3C84(members + 0x1518, memberDeleting);
                        fn_125_3D08(members + 0x1504, memberDeleting);
                        if (members + 0x14EC != 0) {
                            fn_27_1A405C(members + 0x14EC, memberDeleting);
                        }
                        fn_125_3D68(members + 0x1448, memberDeleting);
                        fn_125_3E90(members + 0x1410, memberDeleting);
                        fn_27_C74E8(members + 0x1400, memberDeleting);
                    }
                    fn_125_3EF0(members + 0x135C, memberDeleting);
                    fn_125_4024(members + 0x1328, memberDeleting);
                    fn_125_4080(members + 0x1310, memberDeleting);
                    fn_125_40DC(members + 0x11AC, memberDeleting);
                    fn_125_4148(members + 0x1144, memberDeleting);
                    fn_125_41A8(members + 0x1138, memberDeleting);
                    fn_125_4208(members + 0x1110, memberDeleting);
                    fn_125_5570(members + 0xF40, memberDeleting);
                    fn_125_4264(members + 0xEDC, memberDeleting);
                    fn_125_4330(members + 0xEA0, memberDeleting);
                    fn_125_438C(members + 0xDE8, memberDeleting);
                    if (members + 0xBDC != 0) {
                        fn_27_13C90(members + 0xC78, memberDeleting);
                        fn_27_21038(members + 0xC64, memberDeleting);
                        fn_125_445C(members + 0xBDC, memberDeleting);
                    }
                    fn_125_44E4(members + 0x9FC, memberDeleting);
                    fn_125_4550(members + 0x9CC, memberDeleting);
                    fn_125_4608(members + 0x9BC, memberDeleting);
                    fn_125_4648(members + 0x9A4, memberDeleting);
                    __dt__16soModuleAccesserFv(members + 0x8C4, memberDeleting);
                    fn_125_46A4(members + 0xCC, memberDeleting);
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