#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_95_37C8(void*, short);
void* fn_95_3808(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_95_39D0(void*, short);
void* fn_95_4F9C(void*, short);
void* fn_95_5028(void*, short);
void* fn_95_50B4(void*, short);
void* fn_95_22E0(void*, short);
void* fn_95_237C(void*, short);
void* fn_95_23BC(void*, short);
void* fn_27_C7770(void*, short);
void* fn_95_3AC8(void*, short);
void* fn_95_3B24(void*, short);
void* fn_95_3B80(void*, short);
void* fn_95_3C0C(void*, short);
void* fn_95_3D08(void*, short);
void* fn_95_3EE8(void*, short);
void* fn_95_3F6C(void*, short);
void* fn_27_1A405C(void*, short);
void* fn_95_3FCC(void*, short);
void* fn_95_40F4(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_95_4154(void*, short);
void* fn_95_4288(void*, short);
void* fn_95_42E4(void*, short);
void* fn_95_4340(void*, short);
void* fn_95_43AC(void*, short);
void* fn_95_440C(void*, short);
void* fn_95_446C(void*, short);
void* fn_95_44C8(void*, short);
void* fn_95_454C(void*, short);
void* fn_95_4618(void*, short);
void* fn_95_4674(void*, short);
void* fn_95_46E0(void*, short);
void* fn_95_5140(void*, short);
void* fn_95_4854(void*, short);
void* fn_95_48C0(void*, short);
void* fn_95_4978(void*, short);
void* fn_95_49B8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_95_4A14(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_95_5E38(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        if (members + 0x1FA8 != 0) {
            if (members + 0x1FA8 != 0) {
                fn_95_37C8(members + 0x1FA8, static_cast<short>(0));
            }
        }
        if (object != 0) {
            short memberDeleting = -1;
            fn_95_3808(members + 0x1F60, memberDeleting);
            fn_27_1DBB60(members + 0x1F28, memberDeleting);
            if (members + 0xCC != 0) {
                if (members + 0x1978 != 0) {
                    fn_95_39D0(members + 0x1E28, memberDeleting);
                    fn_95_4F9C(members + 0x1CFC, memberDeleting);
                    fn_95_5028(members + 0x1BD0, memberDeleting);
                    fn_95_50B4(members + 0x1AA4, memberDeleting);
                    if (members + 0x1978 != 0) {
                        fn_95_22E0(members + 0x1A54, memberDeleting);
                        fn_95_237C(members + 0x1A38, memberDeleting);
                        fn_95_23BC(members + 0x198C, memberDeleting);
                        if (members + 0x1978 != 0) {
                            fn_27_C7770(members + 0x1978, memberDeleting);
                        }
                    }
                }
                if (members + 0xCC != 0) {
                    fn_95_3AC8(members + 0x1934, memberDeleting);
                    fn_95_3B24(members + 0x191C, memberDeleting);
                    fn_95_3B80(members + 0x1780, memberDeleting);
                    fn_95_3C0C(members + 0x1720, memberDeleting);
                    fn_95_3D08(members + 0x166C, memberDeleting);
                    if (members + 0x14A4 != 0) {
                        fn_95_3EE8(members + 0x15BC, memberDeleting);
                        fn_95_3F6C(members + 0x15A8, memberDeleting);
                        if (members + 0x1590 != 0) {
                            fn_27_1A405C(members + 0x1590, memberDeleting);
                        }
                        fn_95_3FCC(members + 0x14EC, memberDeleting);
                        fn_95_40F4(members + 0x14B4, memberDeleting);
                        fn_27_C74E8(members + 0x14A4, memberDeleting);
                    }
                    fn_95_4154(members + 0x1400, memberDeleting);
                    fn_95_4288(members + 0x13CC, memberDeleting);
                    fn_95_42E4(members + 0x13B4, memberDeleting);
                    fn_95_4340(members + 0x1250, memberDeleting);
                    fn_95_43AC(members + 0x11E8, memberDeleting);
                    fn_95_440C(members + 0x11DC, memberDeleting);
                    fn_95_446C(members + 0x11B4, memberDeleting);
                    fn_95_44C8(members + 0xFE4, memberDeleting);
                    fn_95_454C(members + 0xF80, memberDeleting);
                    fn_95_4618(members + 0xF44, memberDeleting);
                    fn_95_4674(members + 0xE9C, memberDeleting);
                    fn_95_46E0(members + 0xDE8, memberDeleting);
                    fn_95_5140(members + 0xBDC, memberDeleting);
                    fn_95_4854(members + 0x9FC, memberDeleting);
                    fn_95_48C0(members + 0x9CC, memberDeleting);
                    fn_95_4978(members + 0x9BC, memberDeleting);
                    fn_95_49B8(members + 0x9A4, memberDeleting);
                    __dt__16soModuleAccesserFv(members + 0x8C4, memberDeleting);
                    fn_95_4A14(members + 0xCC, memberDeleting);
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
