#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_125_3720(void*, short);
void* fn_125_3760(void*, short);
void* fn_125_37CC(void*, short);
void* fn_125_3858(void*, short);
void* fn_125_38E4(void*, short);
void* fn_125_3970(void*, short);
void* fn_125_39FC(void*, short);
void* fn_27_BED74(void*, short);
void* fn_125_3A58(void*, short);
void* fn_125_3AE4(void*, short);
void* fn_125_3BE0(void*, short);
void* fn_125_3EF0(void*, short);
void* fn_125_4024(void*, short);
void* fn_125_4080(void*, short);
void* fn_125_40DC(void*, short);
void* fn_125_4148(void*, short);
void* fn_125_41A8(void*, short);
void* fn_125_4208(void*, short);
void* fn_125_4264(void*, short);
void* fn_125_4330(void*, short);
void* fn_125_438C(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_125_4400(void*, short);
void* fn_125_445C(void*, short);
void* fn_125_44E4(void*, short);
void* fn_125_4550(void*, short);
void* fn_125_4608(void*, short);
void* fn_125_4648(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_125_46A4(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_125_3504(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        if (members + 0x1D5C != 0) {
            if (members + 0x1D5C != 0) {
                fn_125_3720(members + 0x1D5C, static_cast<short>(0));
            }
        }
        if (object != 0) {
            short memberDeleting = -1;
            if (members + 0xCC != 0) {
                if (members + 0x17A4 != 0) {
                    fn_125_3760(members + 0x1C54, memberDeleting);
                    fn_125_37CC(members + 0x1B28, memberDeleting);
                    fn_125_3858(members + 0x19FC, memberDeleting);
                    fn_125_38E4(members + 0x18D0, memberDeleting);
                    fn_125_3970(members + 0x17A4, memberDeleting);
                }
                if (members + 0xCC != 0) {
                    fn_125_39FC(members + 0x1788, memberDeleting);
                    if (members + 0x1630 != 0) {
                        fn_27_BED74(members + 0x1630, memberDeleting);
                    }
                    fn_125_3A58(members + 0x1498, memberDeleting);
                    fn_125_3AE4(members + 0x1438, memberDeleting);
                    fn_125_3BE0(members + 0x1278, memberDeleting);
                    fn_125_3EF0(members + 0x11D4, memberDeleting);
                    fn_125_4024(members + 0x11A0, memberDeleting);
                    fn_125_4080(members + 0x1188, memberDeleting);
                    fn_125_40DC(members + 0x1024, memberDeleting);
                    fn_125_4148(members + 0xFBC, memberDeleting);
                    fn_125_41A8(members + 0xFB0, memberDeleting);
                    fn_125_4208(members + 0xF88, memberDeleting);
                    fn_125_4264(members + 0xF18, memberDeleting);
                    fn_125_4330(members + 0xEDC, memberDeleting);
                    fn_125_438C(members + 0xE24, memberDeleting);
                    if (members + 0xBDC != 0) {
                        fn_27_13C90(members + 0xCB4, memberDeleting);
                        fn_27_21038(members + 0xCA0, memberDeleting);
                        fn_125_4400(members + 0xC64, memberDeleting);
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
