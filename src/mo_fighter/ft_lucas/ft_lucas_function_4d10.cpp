#pragma force_active on
void operator delete(void*);

extern "C" {
void fn_114_39C4(void*, short);
void fn_114_3A60(void*, short);
void fn_114_3AA0(void*, short);
void fn_27_1DBB60(void*, short);
void fn_114_3AFC(void*, short);
void fn_114_232C(void*, short);
void fn_114_23C8(void*, short);
void fn_114_2408(void*, short);
void fn_27_C7770(void*, short);
void fn_114_3B68(void*, short);
void fn_114_3BC4(void*, short);
void fn_114_3C20(void*, short);
void fn_114_3C7C(void*, short);
void fn_114_3D08(void*, short);
void fn_114_3E04(void*, short);
void fn_114_3FE4(void*, short);
void fn_114_4068(void*, short);
void fn_27_1A301C(void*, short);
void fn_114_40C8(void*, short);
void fn_114_5120(void*, short);
void fn_27_C74E8(void*, short);
void fn_114_41F0(void*, short);
void fn_114_4324(void*, short);
void fn_114_43E4(void*, short);
void fn_114_4440(void*, short);
void fn_114_44AC(void*, short);
void fn_114_450C(void*, short);
void fn_114_456C(void*, short);
void fn_27_5CC1C(void*, short);
void fn_27_D3080(void*, short);
void __dt__24soCollisionHitModuleImplFv(void*, short);
void fn_27_CC984(void*, short);
void fn_27_4CAA0(void*, short);
void fn_27_CC654(void*, short);
void __dt__27soCollisionAttackModuleImplFv(void*, short);
void fn_27_82AD4(void*, short);
void fn_27_19CCC8(void*, short);
void fn_114_464C(void*, short);
void fn_114_4718(void*, short);
void fn_114_4774(void*, short);
void fn_114_47E0(void*, short);
void fn_27_13C90(void*, short);
void fn_27_21038(void*, short);
void fn_114_4854(void*, short);
void fn_114_48DC(void*, short);
void fn_114_4948(void*, short);
void fn_114_4A00(void*, short);
void fn_114_4A40(void*, short);
void __dt__16soModuleAccesserFv(void*, short);
void fn_114_4A9C(void*, short);
void fn_27_1D81C8(void*, short);
}

extern "C" void* fn_114_4D10(void* object, short deleting) {
    void* result = object;
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_114_39C4(members + 0x23F4, memberDeleting);
        if (members + 0x23B0 != 0) {
            if (members + 0x23B0 != 0) {
                fn_114_3A60(members + 0x23B0, static_cast<short>(0));
            }
        }
        if (object != 0) {
            fn_114_3AA0(members + 0x2368, memberDeleting);
            fn_27_1DBB60(members + 0x2330, memberDeleting);
            if (members + 0xCC != 0) {
                if (members + 0x1D80 != 0) {
                    fn_114_3AFC(members + 0x2230, memberDeleting);
                    if (members + 0x2104 != 0) {
                        fn_114_232C(members + 0x21E0, memberDeleting);
                        fn_114_23C8(members + 0x21C4, memberDeleting);
                        fn_114_2408(members + 0x2118, memberDeleting);
                        if (members + 0x2104 != 0) {
                            fn_27_C7770(members + 0x2104, memberDeleting);
                        }
                    }
                    if (members + 0x1FD8 != 0) {
                        fn_114_232C(members + 0x20B4, memberDeleting);
                        fn_114_23C8(members + 0x2098, memberDeleting);
                        fn_114_2408(members + 0x1FEC, memberDeleting);
                        if (members + 0x1FD8 != 0) {
                            fn_27_C7770(members + 0x1FD8, memberDeleting);
                        }
                    }
                    if (members + 0x1EAC != 0) {
                        fn_114_232C(members + 0x1F88, memberDeleting);
                        fn_114_23C8(members + 0x1F6C, memberDeleting);
                        fn_114_2408(members + 0x1EC0, memberDeleting);
                        if (members + 0x1EAC != 0) {
                            fn_27_C7770(members + 0x1EAC, memberDeleting);
                        }
                    }
                    if (members + 0x1D80 != 0) {
                        fn_114_232C(members + 0x1E5C, memberDeleting);
                        fn_114_23C8(members + 0x1E40, memberDeleting);
                        fn_114_2408(members + 0x1D94, memberDeleting);
                        if (members + 0x1D80 != 0) {
                            fn_27_C7770(members + 0x1D80, memberDeleting);
                        }
                    }
                }
                if (members + 0xCC != 0) {
                    fn_114_3B68(members + 0x1D64, memberDeleting);
                    fn_114_3BC4(members + 0x1D24, memberDeleting);
                    fn_114_3C20(members + 0x1D0C, memberDeleting);
                    fn_114_3C7C(members + 0x1B70, memberDeleting);
                    fn_114_3D08(members + 0x1B10, memberDeleting);
                    fn_114_3E04(members + 0x1A5C, memberDeleting);
                    if (members + 0x1898 != 0) {
                        fn_114_3FE4(members + 0x19AC, memberDeleting);
                        fn_114_4068(members + 0x1998, memberDeleting);
                        if (members + 0x1984 != 0) {
                            fn_27_1A301C(members + 0x1984, memberDeleting);
                        }
                        fn_114_40C8(members + 0x18E0, memberDeleting);
                        fn_114_5120(members + 0x18A8, memberDeleting);
                        fn_27_C74E8(members + 0x1898, memberDeleting);
                    }
                    fn_114_41F0(members + 0x17F4, memberDeleting);
                    fn_114_4324(members + 0x17C0, memberDeleting);
                    fn_114_43E4(members + 0x17A8, memberDeleting);
                    fn_114_4440(members + 0x1644, memberDeleting);
                    fn_114_44AC(members + 0x15DC, memberDeleting);
                    fn_114_450C(members + 0x15D0, memberDeleting);
                    fn_114_456C(members + 0x15A8, memberDeleting);
                    if (members + 0x144C != 0) {
                        fn_27_5CC1C(members + 0x14F8, memberDeleting);
                        if (members + 0x144C != 0) {
                            fn_27_D3080(members + 0x144C, memberDeleting);
                        }
                    }
                    if (members + 0x1238 != 0) {
                        __dt__24soCollisionHitModuleImplFv(members + 0x13DC, memberDeleting);
                        fn_27_CC984(members + 0x1398, memberDeleting);
                        fn_27_4CAA0(members + 0x1314, memberDeleting);
                        fn_27_CC654(members + 0x1238, memberDeleting);
                    }
                    if (members + 0xFE4 != 0) {
                        __dt__27soCollisionAttackModuleImplFv(members + 0x1198, memberDeleting);
                        fn_27_82AD4(members + 0x1194, memberDeleting);
                        fn_27_4CAA0(members + 0x1110, memberDeleting);
                        fn_27_19CCC8(members + 0xFE4, memberDeleting);
                    }
                    fn_114_464C(members + 0xF80, memberDeleting);
                    fn_114_4718(members + 0xF44, memberDeleting);
                    fn_114_4774(members + 0xE9C, memberDeleting);
                    fn_114_47E0(members + 0xDE8, memberDeleting);
                    if (members + 0xBDC != 0) {
                        fn_27_13C90(members + 0xC78, memberDeleting);
                        fn_27_21038(members + 0xC64, memberDeleting);
                        fn_114_4854(members + 0xBDC, memberDeleting);
                    }
                    fn_114_48DC(members + 0x9FC, memberDeleting);
                    fn_114_4948(members + 0x9CC, memberDeleting);
                    fn_114_4A00(members + 0x9BC, memberDeleting);
                    fn_114_4A40(members + 0x9A4, memberDeleting);
                    __dt__16soModuleAccesserFv(members + 0x8C4, memberDeleting);
                    fn_114_4A9C(members + 0xCC, memberDeleting);
                }
            }
            fn_27_1D81C8(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return result;
}
