#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_97_37F8(void*, short);
void* fn_97_3838(void*, short);
void* fn_97_38A4(void*, short);
void* fn_97_3930(void*, short);
void* fn_97_39BC(void*, short);
void* fn_97_2210(void*, short);
void* fn_97_22AC(void*, short);
void* fn_97_22EC(void*, short);
void* fn_27_C7770(void*, short);
void* fn_97_4CC4(void*, short);
void* fn_97_3AD4(void*, short);
void* fn_97_3B30(void*, short);
void* fn_97_3BBC(void*, short);
void* fn_97_3D5C(void*, short);
void* fn_97_3DE0(void*, short);
void* fn_27_1A405C(void*, short);
void* fn_97_3E40(void*, short);
void* fn_97_3F68(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_97_3FC8(void*, short);
void* fn_97_40FC(void*, short);
void* fn_97_4158(void*, short);
void* fn_97_41B4(void*, short);
void* fn_97_4220(void*, short);
void* fn_97_4280(void*, short);
void* fn_97_42E0(void*, short);
void* fn_97_5648(void*, short);
void* fn_97_433C(void*, short);
void* fn_97_4408(void*, short);
void* fn_97_4464(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_97_4534(void*, short);
void* fn_97_45BC(void*, short);
void* fn_97_4628(void*, short);
void* fn_97_46E0(void*, short);
void* fn_97_4720(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_97_4FA8(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_97_53B4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        if (members + 0x1DB4 != 0) {
            if (members + 0x1DB4 != 0) {
                fn_97_37F8(members + 0x1DB4, static_cast<short>(0));
            }
        }
        if (object != 0) {
            short memberDeleting = -1;
            if (members + 0xCC != 0) {
                if (members + 0x17FC != 0) {
                    fn_97_3838(members + 0x1CAC, memberDeleting);
                    fn_97_38A4(members + 0x1B80, memberDeleting);
                    fn_97_3930(members + 0x1A54, memberDeleting);
                    fn_97_39BC(members + 0x1928, memberDeleting);
                    if (members + 0x17FC != 0) {
                        fn_97_2210(members + 0x18D8, memberDeleting);
                        fn_97_22AC(members + 0x18BC, memberDeleting);
                        fn_97_22EC(members + 0x1810, memberDeleting);
                        if (members + 0x17FC != 0) {
                            fn_27_C7770(members + 0x17FC, memberDeleting);
                        }
                    }
                }
                if (members + 0xCC != 0) {
                    fn_97_4CC4(members + 0x17E0, memberDeleting);
                    fn_97_3AD4(members + 0x17C4, memberDeleting);
                    fn_97_3B30(members + 0x1628, memberDeleting);
                    fn_97_3BBC(members + 0x15C8, memberDeleting);
                    if (members + 0x1400 != 0) {
                        fn_97_3D5C(members + 0x1518, memberDeleting);
                        fn_97_3DE0(members + 0x1504, memberDeleting);
                        if (members + 0x14EC != 0) {
                            fn_27_1A405C(members + 0x14EC, memberDeleting);
                        }
                        fn_97_3E40(members + 0x1448, memberDeleting);
                        fn_97_3F68(members + 0x1410, memberDeleting);
                        fn_27_C74E8(members + 0x1400, memberDeleting);
                    }
                    fn_97_3FC8(members + 0x135C, memberDeleting);
                    fn_97_40FC(members + 0x1328, memberDeleting);
                    fn_97_4158(members + 0x1310, memberDeleting);
                    fn_97_41B4(members + 0x11AC, memberDeleting);
                    fn_97_4220(members + 0x1144, memberDeleting);
                    fn_97_4280(members + 0x1138, memberDeleting);
                    fn_97_42E0(members + 0x1110, memberDeleting);
                    fn_97_5648(members + 0xF40, memberDeleting);
                    fn_97_433C(members + 0xEDC, memberDeleting);
                    fn_97_4408(members + 0xEA0, memberDeleting);
                    fn_97_4464(members + 0xDE8, memberDeleting);
                    if (members + 0xBDC != 0) {
                        fn_27_13C90(members + 0xC78, memberDeleting);
                        fn_27_21038(members + 0xC64, memberDeleting);
                        fn_97_4534(members + 0xBDC, memberDeleting);
                    }
                    fn_97_45BC(members + 0x9FC, memberDeleting);
                    fn_97_4628(members + 0x9CC, memberDeleting);
                    fn_97_46E0(members + 0x9BC, memberDeleting);
                    fn_97_4720(members + 0x9A4, memberDeleting);
                    __dt__16soModuleAccesserFv(members + 0x8C4, memberDeleting);
                    fn_97_4FA8(members + 0xCC, memberDeleting);
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
