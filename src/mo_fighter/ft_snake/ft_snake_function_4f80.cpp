#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_122_51B0(void*, short);
void* fn_122_3BC4(void*, short);
void* fn_122_3C20(void*, short);
void* fn_122_3C7C(void*, short);
void* fn_122_3D5C(void*, short);
void* fn_27_93100(void*, short);
void* fn_122_523C(void*, short);
void* fn_122_5A94(void*, short);
void* fn_27_19EFFC(void*, short);
void* fn_27_1A51A0(void*, short);
void* fn_122_3DE8(void*, short);
void* fn_122_430C(void*, short);
void* fn_122_4440(void*, short);
void* fn_122_44FC(void*, short);
void* fn_122_4558(void*, short);
void* fn_122_45C4(void*, short);
void* fn_122_4624(void*, short);
void* fn_122_4684(void*, short);
void* fn_122_4850(void*, short);
void* fn_122_5B54(void*, short);
void* fn_122_5BC8(void*, short);
void* fn_122_4B58(void*, short);
void* fn_122_4BC4(void*, short);
void* fn_122_4C7C(void*, short);
void* fn_122_4CBC(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_122_4D18(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_122_4F80(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (object != 0) {
            if (storage + 0xCC != 0) {
                if (storage + 0x7BA8 != 0) {
                    fn_122_51B0(storage + 0x7BAC, -1);
                }
                if (storage + 0xCC != 0) {
                    fn_122_3BC4(storage + 0x7B8C, -1);
                    fn_122_3C20(storage + 0x7B4C, -1);
                    fn_122_3C7C(storage + 0x7B34, -1);
                    fn_122_3D5C(storage + 0x7998, -1);
                    if (storage + 0x1260 != 0) {
                        if (storage + 0x795C != 0) {
                            fn_27_93100(storage + 0x795C, 0);
                        }
                        if (storage + 0x12A0 != 0) {
                            if (storage + 0x12A0 != 0) {
                                if (storage + 0x12A8 != 0) {
                                    if (storage + 0x12A8 != 0) {
                                        if (storage + 0x12AC != 0) {
                                            fn_122_523C(storage + 0x5724, -1);
                                            if (storage + 0x12B0 != 0) {
                                                fn_122_523C(storage + 0x34F0, -1);
                                                if (storage + 0x12B4 != 0) {
                                                    fn_122_523C(storage + 0x12BC, -1);
                                                }
                                            }
                                        }
                                    }
                                }
                                fn_122_5A94(storage + 0x12A0, 0);
                            }
                        }
                        fn_27_19EFFC(storage + 0x1274, -1);
                        fn_27_1A51A0(storage + 0x1260, -1);
                    }
                    fn_122_3DE8(storage + 0x1204, -1);
                    fn_122_430C(storage + 0x115C, -1);
                    fn_122_4440(storage + 0x1128, -1);
                    fn_122_44FC(storage + 0x1110, -1);
                    fn_122_4558(storage + 0xFAC, -1);
                    fn_122_45C4(storage + 0xF44, -1);
                    fn_122_4624(storage + 0xF38, -1);
                    fn_122_4684(storage + 0xF10, -1);
                    fn_122_4850(storage + 0xEA0, -1);
                    fn_122_5B54(storage + 0xDE8, -1);
                    fn_122_5BC8(storage + 0xBDC, -1);
                    fn_122_4B58(storage + 0x9FC, -1);
                    fn_122_4BC4(storage + 0x9CC, -1);
                    fn_122_4C7C(storage + 0x9BC, -1);
                    fn_122_4CBC(storage + 0x9A4, -1);
                    __dt__16soModuleAccesserFv(storage + 0x8C4, -1);
                    fn_122_4D18(storage + 0xCC, -1);
                }
            }
            fn_27_1D81C8(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
