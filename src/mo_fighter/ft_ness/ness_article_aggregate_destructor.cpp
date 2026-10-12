void operator delete(void*);
extern "C" {
void* fn_101_3B0C(void*, short);
void* fn_101_3B4C(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_101_3BA8(void*, short);
void* fn_101_57F0(void*, short);
void* fn_101_587C(void*, short);
void* fn_101_5908(void*, short);
void* fn_101_6CAC(void*, short);
void* fn_101_3C70(void*, short);
void* fn_101_3CCC(void*, short);
void* fn_101_6D38(void*, short);
void* fn_27_10424(void*, short);
void* fn_101_3D28(void*, short);
void* fn_101_3DB4(void*, short);
void* fn_101_3EB0(void*, short);
void* fn_101_4090(void*, short);
void* fn_101_4114(void*, short);
void* fn_101_6D94(void*, short);
void* fn_101_4174(void*, short);
void* fn_101_3E14(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_101_429C(void*, short);
void* fn_101_43D0(void*, short);
void* fn_101_4490(void*, short);
void* fn_101_5C30(void*, short);
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
void* fn_101_6DF0(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_101_6A20(void* object, short deleting) {
    unsigned char* members = static_cast<unsigned char*>(object);
    if (object != 0) {
        // Preserve the null checks of the nested, non-deleting destructors.
        if (members + 0x2104 != 0) {
            if (members + 0x2104 != 0) {
                short baseDeleting = 0;
                fn_101_3B0C(members + 0x2104, baseDeleting);
            }
        }
        if (object != 0) {
            short memberDeleting = -1;
            fn_101_3B4C(members + 0x20BC, memberDeleting);
            fn_27_1DBB60(members + 0x2084, memberDeleting);
            if (members + 0xCC != 0) {
                if (members + 0x1AD4 != 0) {
                    fn_101_3BA8(members + 0x1F84, memberDeleting);
                    fn_101_57F0(members + 0x1E58, memberDeleting);
                    fn_101_587C(members + 0x1D2C, memberDeleting);
                    fn_101_5908(members + 0x1C00, memberDeleting);
                    fn_101_6CAC(members + 0x1AD4, memberDeleting);
                }
                if (members + 0xCC != 0) {
                    short innerDeleting = -1;
                    fn_101_3C70(members + 0x1A90, innerDeleting);
                    fn_101_3CCC(members + 0x1A78, innerDeleting);
                    fn_101_6D38(members + 0x1920, innerDeleting);
                    if (members + 0x18D0 != 0) {
                        fn_27_10424(members + 0x18D4, innerDeleting);
                    }
                    short moduleDeleting = -1;
                    fn_101_3D28(members + 0x173C, moduleDeleting);
                    fn_101_3DB4(members + 0x16DC, moduleDeleting);
                    fn_101_3EB0(members + 0x1628, moduleDeleting);
                    if (members + 0x1440 != 0) {
                        fn_101_4090(members + 0x1578, moduleDeleting);
                        fn_101_4114(members + 0x1564, moduleDeleting);
                        fn_101_6D94(members + 0x154C, moduleDeleting);
                        fn_101_4174(members + 0x14A8, moduleDeleting);
                        if (members + 0x1450 != 0) {
                            fn_101_3E14(members + 0x1484, moduleDeleting);
                        }
                        short baseDeleting = -1;
                        fn_27_C74E8(members + 0x1440, baseDeleting);
                    }
                    short accesserDeleting = -1;
                    fn_101_429C(members + 0x139C, accesserDeleting);
                    fn_101_43D0(members + 0x1368, accesserDeleting);
                    fn_101_4490(members + 0x1350, accesserDeleting);
                    fn_101_5C30(members + 0x11B8, accesserDeleting);
                    fn_101_4558(members + 0x1150, accesserDeleting);
                    fn_101_45B8(members + 0x1144, accesserDeleting);
                    fn_101_4618(members + 0x111C, accesserDeleting);
                    fn_101_4674(members + 0xF4C, accesserDeleting);
                    fn_101_46F8(members + 0xEE8, accesserDeleting);
                    fn_101_47C4(members + 0xEAC, accesserDeleting);
                    fn_101_488C(members + 0xDF4, accesserDeleting);
                    fn_101_5C9C(members + 0xBE8, accesserDeleting);
                    fn_101_4988(members + 0xA08, accesserDeleting);
                    fn_101_49F4(members + 0x9D8, accesserDeleting);
                    fn_101_4AAC(members + 0x9C8, accesserDeleting);
                    fn_101_4AEC(members + 0x9B0, accesserDeleting);
                    __dt__16soModuleAccesserFv(members + 0x8D0, accesserDeleting);
                    fn_101_6DF0(members + 0xCC, accesserDeleting);
                }
            }
            short baseDeleting = 0;
            fn_27_1D81C8(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
