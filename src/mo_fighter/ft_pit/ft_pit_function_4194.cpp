#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_112_4480(void*, short);
void* fn_112_44C0(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_112_455C(void*, short);
void* fn_112_45C8(void*, short);
void* fn_112_4654(void*, short);
void* fn_112_46E0(void*, short);
void* fn_112_21EC(void*, short);
void* fn_112_2288(void*, short);
void* fn_112_22C8(void*, short);
void* fn_27_C7770(void*, short);
void* fn_27_C31CC(void*, short);
void* fn_112_3698(void*, short);
void* fn_112_36F4(void*, short);
void* fn_112_3750(void*, short);
void* fn_112_37DC(void*, short);
void* fn_112_476C(void*, short);
void* fn_112_48A8(void*, short);
void* fn_112_492C(void*, short);
void* fn_27_1A405C(void*, short);
void* fn_112_498C(void*, short);
void* fn_112_4A14(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_112_4A74(void*, short);
void* fn_112_38D8(void*, short);
void* __dt__22soControllerModuleImplFv(void*, short);
void* fn_112_3990(void*, short);
void* fn_112_39FC(void*, short);
void* fn_112_3A5C(void*, short);
void* fn_112_3ABC(void*, short);
void* fn_112_4BA8(void*, short);
void* fn_112_3B18(void*, short);
void* fn_112_4C2C(void*, short);
void* fn_112_4C88(void*, short);
void* fn_112_4CF4(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_112_3BE4(void*, short);
void* fn_112_3D68(void*, short);
void* fn_112_3DD4(void*, short);
void* fn_112_3E8C(void*, short);
void* fn_112_3ECC(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_112_3F28(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_112_4194(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x1F88 != 0) {
            if (storage + 0x1F88 != 0) {
                fn_112_4480(storage + 0x1F88, 0);
            }
        }
        if (object != 0) {
            fn_112_44C0(storage + 0x1F40, -1);
            fn_27_1DBB60(storage + 0x1F08, -1);
            if (storage + 0xCC != 0) {
                if (storage + 0x1958 != 0) {
                    fn_112_455C(storage + 0x1E08, -1);
                    fn_112_45C8(storage + 0x1CDC, -1);
                    fn_112_4654(storage + 0x1BB0, -1);
                    fn_112_46E0(storage + 0x1A84, -1);
                    if (storage + 0x1958 != 0) {
                        fn_112_21EC(storage + 0x1A34, -1);
                        fn_112_2288(storage + 0x1A18, -1);
                        fn_112_22C8(storage + 0x196C, -1);
                        if (storage + 0x1958 != 0) {
                            fn_27_C7770(storage + 0x1958, -1);
                        }
                    }
                }
                if (storage + 0xCC != 0) {
                    if (storage + 0x193C != 0) {
                        fn_27_C31CC(storage + 0x193C, -1);
                    }
                    fn_112_3698(storage + 0x18FC, -1);
                    fn_112_36F4(storage + 0x18E4, -1);
                    fn_112_3750(storage + 0x1748, -1);
                    fn_112_37DC(storage + 0x16E8, -1);
                    fn_112_476C(storage + 0x1634, -1);
                    if (storage + 0x146C != 0) {
                        fn_112_48A8(storage + 0x1584, -1);
                        fn_112_492C(storage + 0x1570, -1);
                        if (storage + 0x1558 != 0) {
                            fn_27_1A405C(storage + 0x1558, -1);
                        }
                        fn_112_498C(storage + 0x14B4, -1);
                        fn_112_4A14(storage + 0x147C, -1);
                        fn_27_C74E8(storage + 0x146C, -1);
                    }
                    fn_112_4A74(storage + 0x13C8, -1);
                    fn_112_38D8(storage + 0x1394, -1);
                    if (storage + 0x1370 != 0) {
                        if (storage + 0x1374 != 0) {
                            __dt__22soControllerModuleImplFv(storage + 0x1374, 0);
                        }
                    }
                    fn_112_3990(storage + 0x1208, -1);
                    fn_112_39FC(storage + 0x11A0, -1);
                    fn_112_3A5C(storage + 0x1194, -1);
                    fn_112_3ABC(storage + 0x116C, -1);
                    fn_112_4BA8(storage + 0xF9C, -1);
                    fn_112_3B18(storage + 0xF38, -1);
                    fn_112_4C2C(storage + 0xEFC, -1);
                    fn_112_4C88(storage + 0xE54, -1);
                    fn_112_4CF4(storage + 0xDA0, -1);
                    if (storage + 0xBDC != 0) {
                        fn_27_13C90(storage + 0xC30, -1);
                        fn_27_21038(storage + 0xC1C, -1);
                        fn_112_3BE4(storage + 0xBE0, -1);
                    }
                    fn_112_3D68(storage + 0x9FC, -1);
                    fn_112_3DD4(storage + 0x9CC, -1);
                    fn_112_3E8C(storage + 0x9BC, -1);
                    fn_112_3ECC(storage + 0x9A4, -1);
                    __dt__16soModuleAccesserFv(storage + 0x8C4, -1);
                    fn_112_3F28(storage + 0xCC, -1);
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
