#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_105_3674(void*, short);
void* fn_105_36B4(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_105_3750(void*, short);
void* fn_105_3A24(void*, short);
void* fn_105_3A80(void*, short);
void* fn_105_3ADC(void*, short);
void* fn_105_3B38(void*, short);
void* fn_105_3BC4(void*, short);
void* fn_105_3CC0(void*, short);
void* fn_105_3DFC(void*, short);
void* fn_105_4160(void*, short);
void* fn_105_4294(void*, short);
void* fn_105_42F0(void*, short);
void* fn_105_434C(void*, short);
void* fn_105_43B8(void*, short);
void* fn_105_4418(void*, short);
void* fn_105_4478(void*, short);
void* fn_105_44D4(void*, short);
void* fn_105_4558(void*, short);
void* fn_105_4624(void*, short);
void* fn_105_4680(void*, short);
void* fn_105_46F4(void*, short);
void* fn_105_47F4(void*, short);
void* fn_105_4860(void*, short);
void* fn_105_4918(void*, short);
void* fn_105_4958(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_105_49B4(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_105_3490(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        if (members + 0x1F14 != 0) {
            if (members + 0x1F14 != 0) {
                fn_105_3674(members + 0x1F14, static_cast<short>(0));
            }
        }
        if (object != 0) {
            short memberDeleting = -1;
            fn_105_36B4(members + 0x1ECC, memberDeleting);
            fn_27_1DBB60(members + 0x1E94, memberDeleting);
            if (members + 0xCC != 0) {
                fn_105_3750(members + 0x18E4, memberDeleting);
                if (members + 0xCC != 0) {
                    fn_105_3A24(members + 0x18C8, memberDeleting);
                    fn_105_3A80(members + 0x1888, memberDeleting);
                    fn_105_3ADC(members + 0x1870, memberDeleting);
                    fn_105_3B38(members + 0x16D4, memberDeleting);
                    fn_105_3BC4(members + 0x1674, memberDeleting);
                    fn_105_3CC0(members + 0x15C0, memberDeleting);
                    fn_105_3DFC(members + 0x1400, memberDeleting);
                    fn_105_4160(members + 0x135C, memberDeleting);
                    fn_105_4294(members + 0x1328, memberDeleting);
                    fn_105_42F0(members + 0x1310, memberDeleting);
                    fn_105_434C(members + 0x11AC, memberDeleting);
                    fn_105_43B8(members + 0x1144, memberDeleting);
                    fn_105_4418(members + 0x1138, memberDeleting);
                    fn_105_4478(members + 0x1110, memberDeleting);
                    fn_105_44D4(members + 0xF40, memberDeleting);
                    fn_105_4558(members + 0xEDC, memberDeleting);
                    fn_105_4624(members + 0xEA0, memberDeleting);
                    fn_105_4680(members + 0xDE8, memberDeleting);
                    fn_105_46F4(members + 0xBDC, memberDeleting);
                    fn_105_47F4(members + 0x9FC, memberDeleting);
                    fn_105_4860(members + 0x9CC, memberDeleting);
                    fn_105_4918(members + 0x9BC, memberDeleting);
                    fn_105_4958(members + 0x9A4, memberDeleting);
                    __dt__16soModuleAccesserFv(members + 0x8C4, memberDeleting);
                    fn_105_49B4(members + 0xCC, memberDeleting);
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
