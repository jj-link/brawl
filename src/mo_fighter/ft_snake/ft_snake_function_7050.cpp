#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_1A74A4(void*, short);
void* fn_122_7270(void*, short);
void* fn_122_3BC4(void*, short);
void* fn_122_3C20(void*, short);
void* fn_122_3C7C(void*, short);
void* fn_122_3D5C(void*, short);
void* fn_27_93100(void*, short);
void* fn_122_738C(void*, short);
void* fn_122_5A94(void*, short);
void* fn_27_19EFFC(void*, short);
void* fn_27_1A51A0(void*, short);
void* fn_122_3DE8(void*, short);
void* fn_122_6E70(void*, short);
void* fn_122_430C(void*, short);
void* fn_122_4440(void*, short);
void* fn_122_767C(void*, short);
void* fn_122_4558(void*, short);
void* fn_122_45C4(void*, short);
void* fn_122_4624(void*, short);
void* fn_122_4684(void*, short);
void* fn_122_4850(void*, short);
void* fn_122_49E4(void*, short);
void* fn_122_5A1C(void*, short);
void* fn_122_4B58(void*, short);
void* fn_122_4BC4(void*, short);
void* fn_122_4C7C(void*, short);
void* fn_122_4CBC(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_122_4D18(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_122_7050(void* object, short deleting) {
    unsigned char* members = static_cast<unsigned char*>(object);
    if (object != 0) {
        short d = -1;
        fn_27_1A74A4(members + 0x67B0, d);
        if (object != 0) {
            if (members + 0xCC != 0) {
                fn_122_7270(members + 0x61FC, d);
                if (members + 0xCC != 0) {
                    fn_122_3BC4(members + 0x61E0, d);
                    fn_122_3C20(members + 0x61A0, d);
                    fn_122_3C7C(members + 0x6188, d);
                    fn_122_3D5C(members + 0x5FEC, d);
                    if (members + 0x148C != 0) {
                        fn_27_93100(members + 0x5FB0, d);
                        if (members + 0x14CC != 0) {
                            if (members + 0x14CC != 0) {
                                if (members + 0x14D4 != 0) {
                                    if (members + 0x14D4 != 0) {
                                        if (members + 0x14D8 != 0) {
                                            fn_122_738C(members + 0x3A48, d);
                                            if (members + 0x14DC != 0) {
                                                fn_122_738C(members + 0x14E4, d);
                                            }
                                        }
                                    }
                                }
                                short zero = 0;
                                fn_122_5A94(members + 0x14CC, zero);
                            }
                        }
                        fn_27_19EFFC(members + 0x14A0, d);
                        fn_27_1A51A0(members + 0x148C, d);
                    }
                    fn_122_3DE8(members + 0x1430, d);
                    fn_122_6E70(members + 0x1270, d);
                    fn_122_430C(members + 0x11CC, d);
                    fn_122_4440(members + 0x1198, d);
                    fn_122_767C(members + 0x1174, d);
                    fn_122_4558(members + 0x100C, d);
                    fn_122_45C4(members + 0xFA4, d);
                    fn_122_4624(members + 0xF98, d);
                    fn_122_4684(members + 0xF70, d);
                    fn_122_4850(members + 0xF00, d);
                    fn_122_49E4(members + 0xDE8, d);
                    fn_122_5A1C(members + 0xBDC, d);
                    fn_122_4B58(members + 0x9FC, d);
                    fn_122_4BC4(members + 0x9CC, d);
                    fn_122_4C7C(members + 0x9BC, d);
                    fn_122_4CBC(members + 0x9A4, d);
                    __dt__16soModuleAccesserFv(members + 0x8C4, d);
                    fn_122_4D18(members + 0xCC, d);
                }
            }
            short zero2 = 0;
            fn_27_1D81C8(object, zero2);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
