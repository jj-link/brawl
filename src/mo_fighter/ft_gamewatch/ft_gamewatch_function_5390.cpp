#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_1F9CC(void*, short);
void* fn_107_3944(void*, short);
void* fn_107_3984(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_107_3A20(void*, short);
void* fn_107_2294(void*, short);
void* fn_107_2330(void*, short);
void* fn_107_2370(void*, short);
void* fn_27_C7770(void*, short);
void* fn_107_50A0(void*, short);
void* fn_107_3A8C(void*, short);
void* fn_107_3AE8(void*, short);
void* fn_107_3B44(void*, short);
void* fn_107_3BA0(void*, short);
void* fn_107_3C2C(void*, short);
void* fn_107_3D28(void*, short);
void* fn_107_512C(void*, short);
void* fn_107_40D0(void*, short);
void* fn_107_4204(void*, short);
void* fn_107_4260(void*, short);
void* fn_107_42BC(void*, short);
void* fn_107_4328(void*, short);
void* fn_107_4388(void*, short);
void* fn_107_43E8(void*, short);
void* fn_107_4444(void*, short);
void* fn_107_44C8(void*, short);
void* fn_107_4594(void*, short);
void* fn_107_465C(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_107_46D0(void*, short);
void* fn_107_472C(void*, short);
void* fn_107_47B4(void*, short);
void* fn_107_4820(void*, short);
void* fn_107_48D8(void*, short);
void* fn_107_4918(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_107_4974(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_107_5390(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1F9CC(storage + 0x20B8, -1);
        if (storage + 0x208C != 0) {
            if (storage + 0x208C != 0) {
                fn_107_3944(storage + 0x208C, 0);
            }
        }
        if (object != 0) {
            fn_107_3984(storage + 0x2044, -1);
            fn_27_1DBB60(storage + 0x200C, -1);
            if (storage + 0xCC != 0) {
                if (storage + 0x1A5C != 0) {
                    fn_107_3A20(storage + 0x1F0C, -1);
                    if (storage + 0x1DE0 != 0) {
                        fn_107_2294(storage + 0x1EBC, -1);
                        fn_107_2330(storage + 0x1EA0, -1);
                        fn_107_2370(storage + 0x1DF4, -1);
                        if (storage + 0x1DE0 != 0) {
                            fn_27_C7770(storage + 0x1DE0, -1);
                        }
                    }
                    if (storage + 0x1CB4 != 0) {
                        fn_107_2294(storage + 0x1D90, -1);
                        fn_107_2330(storage + 0x1D74, -1);
                        fn_107_2370(storage + 0x1CC8, -1);
                        if (storage + 0x1CB4 != 0) {
                            fn_27_C7770(storage + 0x1CB4, -1);
                        }
                    }
                    if (storage + 0x1B88 != 0) {
                        fn_107_2294(storage + 0x1C64, -1);
                        fn_107_2330(storage + 0x1C48, -1);
                        fn_107_2370(storage + 0x1B9C, -1);
                        if (storage + 0x1B88 != 0) {
                            fn_27_C7770(storage + 0x1B88, -1);
                        }
                    }
                    fn_107_50A0(storage + 0x1A5C, -1);
                }
                if (storage + 0xCC != 0) {
                    fn_107_3A8C(storage + 0x1A18, -1);
                    fn_107_3AE8(storage + 0x1A00, -1);
                    fn_107_3B44(storage + 0x18A8, -1);
                    fn_107_3BA0(storage + 0x1710, -1);
                    fn_107_3C2C(storage + 0x16B0, -1);
                    fn_107_3D28(storage + 0x15FC, -1);
                    fn_107_512C(storage + 0x143C, -1);
                    fn_107_40D0(storage + 0x1398, -1);
                    fn_107_4204(storage + 0x1364, -1);
                    fn_107_4260(storage + 0x134C, -1);
                    fn_107_42BC(storage + 0x11E8, -1);
                    fn_107_4328(storage + 0x1180, -1);
                    fn_107_4388(storage + 0x1174, -1);
                    fn_107_43E8(storage + 0x114C, -1);
                    fn_107_4444(storage + 0xF7C, -1);
                    fn_107_44C8(storage + 0xF18, -1);
                    fn_107_4594(storage + 0xEDC, -1);
                    fn_107_465C(storage + 0xE24, -1);
                    if (storage + 0xBDC != 0) {
                        fn_27_13C90(storage + 0xCB4, -1);
                        fn_27_21038(storage + 0xCA0, -1);
                        fn_107_46D0(storage + 0xC64, -1);
                        fn_107_472C(storage + 0xBDC, -1);
                    }
                    fn_107_47B4(storage + 0x9FC, -1);
                    fn_107_4820(storage + 0x9CC, -1);
                    fn_107_48D8(storage + 0x9BC, -1);
                    fn_107_4918(storage + 0x9A4, -1);
                    __dt__16soModuleAccesserFv(storage + 0x8C4, -1);
                    fn_107_4974(storage + 0xCC, -1);
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
