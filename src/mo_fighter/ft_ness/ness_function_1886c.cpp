void operator delete(void*);
extern "C" {
void* fn_101_3B0C(void*, short);
void* fn_101_3B4C(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_101_572C(void*, short);
void* fn_101_3C14(void*, short);
void* fn_101_3C70(void*, short);
void* fn_101_3CCC(void*, short);
void* fn_101_3D28(void*, short);
void* fn_101_3DB4(void*, short);
void* fn_101_3EB0(void*, short);
void* fn_101_4090(void*, short);
void* fn_101_4114(void*, short);
void* fn_101_5BD4(void*, short);
void* fn_101_4174(void*, short);
void* fn_101_3E14(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_101_429C(void*, short);
void* fn_101_43D0(void*, short);
void* fn_101_4490(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_199E3C(void*, short);
void* fn_101_4558(void*, short);
void* fn_101_45B8(void*, short);
void* fn_101_4618(void*, short);
void* fn_101_4674(void*, short);
void* fn_101_46F8(void*, short);
void* fn_101_47C4(void*, short);
void* fn_101_488C(void*, short);
void* fn_101_5C9C(void*, short);
void* fn_101_4988(void*, short);
void* fn_101_49F4(void*, short);
void* fn_101_4AAC(void*, short);
void* fn_101_4AEC(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_101_4B48(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_101_1886C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        // Distinct inlined lifetime layers retain their own receiver guards.
        if (members + 0x1F50 != 0) {
            if (members + 0x1F50 != 0) {
                fn_101_3B0C(members + 0x1F50, static_cast<short>(0));
            }
        }
        if (object != 0) {
            short memberDeleting = -1;
            fn_101_3B4C(members + 0x1F08, memberDeleting);
            fn_27_1DBB60(members + 0x1ED0, memberDeleting);
            if (members + 0xCC != 0) {
                fn_101_572C(members + 0x1920, memberDeleting);
                if (members + 0xCC != 0) {
                    fn_101_3C14(members + 0x1904, memberDeleting);
                    fn_101_3C70(members + 0x18C4, memberDeleting);
                    fn_101_3CCC(members + 0x18AC, memberDeleting);
                    fn_101_3D28(members + 0x1710, memberDeleting);
                    fn_101_3DB4(members + 0x16B0, memberDeleting);
                    fn_101_3EB0(members + 0x15FC, memberDeleting);
                    if (members + 0x1434 != 0) {
                        fn_101_4090(members + 0x154C, memberDeleting);
                        fn_101_4114(members + 0x1538, memberDeleting);
                        fn_101_5BD4(members + 0x1528, memberDeleting);
                        fn_101_4174(members + 0x1484, memberDeleting);
                        if (members + 0x1444 != 0) {
                            fn_101_3E14(members + 0x1460, memberDeleting);
                        }
                        fn_27_C74E8(members + 0x1434, static_cast<short>(-1));
                    }
                    fn_101_429C(members + 0x1390, memberDeleting);
                    fn_101_43D0(members + 0x135C, memberDeleting);
                    fn_101_4490(members + 0x1344, memberDeleting);
                    if (members + 0x11AC != 0) {
                        fn_27_6A3D8(members + 0x12F0, memberDeleting);
                        fn_27_199E3C(members + 0x11AC, memberDeleting);
                    }
                    fn_101_4558(members + 0x1144, memberDeleting);
                    fn_101_45B8(members + 0x1138, memberDeleting);
                    fn_101_4618(members + 0x1110, memberDeleting);
                    fn_101_4674(members + 0xF40, memberDeleting);
                    fn_101_46F8(members + 0xEDC, memberDeleting);
                    fn_101_47C4(members + 0xEA0, memberDeleting);
                    fn_101_488C(members + 0xDE8, memberDeleting);
                    fn_101_5C9C(members + 0xBDC, memberDeleting);
                    fn_101_4988(members + 0x9FC, memberDeleting);
                    fn_101_49F4(members + 0x9CC, memberDeleting);
                    fn_101_4AAC(members + 0x9BC, memberDeleting);
                    fn_101_4AEC(members + 0x9A4, memberDeleting);
                    __dt__16soModuleAccesserFv(members + 0x8C4, memberDeleting);
                    fn_101_4B48(members + 0xCC, memberDeleting);
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
