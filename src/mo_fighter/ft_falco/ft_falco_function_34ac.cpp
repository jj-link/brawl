#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_108_36C8(void*, short);
void* fn_108_3708(void*, short);
void* fn_108_3774(void*, short);
void* fn_108_3800(void*, short);
void* fn_108_388C(void*, short);
void* fn_108_3918(void*, short);
void* fn_108_39A4(void*, short);
void* fn_108_3A00(void*, short);
void* fn_108_3A8C(void*, short);
void* fn_108_3B88(void*, short);
void* fn_108_3E98(void*, short);
void* fn_108_3FCC(void*, short);
void* fn_108_4028(void*, short);
void* fn_108_4084(void*, short);
void* fn_108_40F0(void*, short);
void* fn_108_4150(void*, short);
void* fn_108_41B0(void*, short);
void* fn_108_420C(void*, short);
void* fn_108_42D8(void*, short);
void* fn_108_4334(void*, short);
void* fn_108_43A8(void*, short);
void* fn_108_4404(void*, short);
void* fn_108_448C(void*, short);
void* fn_108_44F8(void*, short);
void* fn_108_45B0(void*, short);
void* fn_108_45F0(void*, short);
void* fn_108_464C(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_27_BED74(void*, short);
void* fn_27_1D81C8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
}

extern "C" void* fn_108_34AC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        if (members + 0x1D5C != 0) {
            if (members + 0x1D5C != 0) {
                fn_108_36C8(members + 0x1D5C, static_cast<short>(0));
            }
        }
        if (object != 0) {
            short memberDeleting = -1;
            if (members + 0xCC != 0) {
                if (members + 0x17A4 != 0) {
                    fn_108_3708(members + 0x1C54, memberDeleting);
                    fn_108_3774(members + 0x1B28, memberDeleting);
                    fn_108_3800(members + 0x19FC, memberDeleting);
                    fn_108_388C(members + 0x18D0, memberDeleting);
                    fn_108_3918(members + 0x17A4, memberDeleting);
                }
                if (members + 0xCC != 0) {
                    fn_108_39A4(members + 0x1788, memberDeleting);
                    if (members + 0x1630 != 0) {
                        fn_27_BED74(members + 0x1630, memberDeleting);
                    }
                    fn_108_3A00(members + 0x1498, memberDeleting);
                    fn_108_3A8C(members + 0x1438, memberDeleting);
                    fn_108_3B88(members + 0x1278, memberDeleting);
                    fn_108_3E98(members + 0x11D4, memberDeleting);
                    fn_108_3FCC(members + 0x11A0, memberDeleting);
                    fn_108_4028(members + 0x1188, memberDeleting);
                    fn_108_4084(members + 0x1024, memberDeleting);
                    fn_108_40F0(members + 0xFBC, memberDeleting);
                    fn_108_4150(members + 0xFB0, memberDeleting);
                    fn_108_41B0(members + 0xF88, memberDeleting);
                    fn_108_420C(members + 0xF18, memberDeleting);
                    fn_108_42D8(members + 0xEDC, memberDeleting);
                    fn_108_4334(members + 0xE24, memberDeleting);
                    if (members + 0xBDC != 0) {
                        fn_27_13C90(members + 0xCB4, memberDeleting);
                        fn_27_21038(members + 0xCA0, memberDeleting);
                        fn_108_43A8(members + 0xC64, memberDeleting);
                        fn_108_4404(members + 0xBDC, memberDeleting);
                    }
                    fn_108_448C(members + 0x9FC, memberDeleting);
                    fn_108_44F8(members + 0x9CC, memberDeleting);
                    fn_108_45B0(members + 0x9BC, memberDeleting);
                    fn_108_45F0(members + 0x9A4, memberDeleting);
                    __dt__16soModuleAccesserFv(members + 0x8C4, memberDeleting);
                    fn_108_464C(members + 0xCC, memberDeleting);
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
