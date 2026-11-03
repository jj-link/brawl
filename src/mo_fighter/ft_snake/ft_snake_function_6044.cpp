#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_122_38A0(void*, short);
void* fn_122_3958(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_122_39B4(void*, short);
void* fn_122_62F4(void*, short);
void* fn_122_6380(void*, short);
void* fn_122_640C(void*, short);
void* fn_122_2158(void*, short);
void* fn_122_21F4(void*, short);
void* fn_122_2234(void*, short);
void* fn_27_C7770(void*, short);
void* fn_122_3BC4(void*, short);
void* fn_122_3C20(void*, short);
void* fn_122_3C7C(void*, short);
void* fn_122_6498(void*, short);
void* fn_122_3D5C(void*, short);
void* fn_122_3DE8(void*, short);
void* fn_122_57B0(void*, short);
void* fn_122_40A0(void*, short);
void* fn_122_4124(void*, short);
void* fn_27_1A4778(void*, short);
void* fn_122_4184(void*, short);
void* fn_122_42AC(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_122_430C(void*, short);
void* fn_122_4440(void*, short);
void* fn_122_44FC(void*, short);
void* fn_122_4558(void*, short);
void* fn_122_45C4(void*, short);
void* fn_122_4624(void*, short);
void* fn_122_4684(void*, short);
void* fn_122_47CC(void*, short);
void* fn_122_5998(void*, short);
void* fn_122_4850(void*, short);
void* fn_122_491C(void*, short);
void* fn_122_5B54(void*, short);
void* fn_122_64F4(void*, short);
void* fn_122_4B58(void*, short);
void* fn_122_4BC4(void*, short);
void* fn_122_4C7C(void*, short);
void* fn_122_4CBC(void*, short);
void* fn_122_4D18(void*, short);
void* fn_27_1D81C8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
}
extern "C" void* fn_122_6044(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_122_38A0(members + 0x2210, static_cast<short>(0));
        if (object != 0) {
            short memberDeleting = -1;
            fn_122_3958(members + 0x21CC, memberDeleting);
            fn_27_1DBB60(members + 0x2194, memberDeleting);
            if (members + 0xCC != 0) {
                if (members + 0x1BE4 != 0) {
                    fn_122_39B4(members + 0x2094, memberDeleting);
                    fn_122_62F4(members + 0x1F68, memberDeleting);
                    fn_122_6380(members + 0x1E3C, memberDeleting);
                    fn_122_640C(members + 0x1D10, memberDeleting);
                    if (members + 0x1BE4 != 0) {
                        fn_122_2158(members + 0x1CC0, memberDeleting);
                        fn_122_21F4(members + 0x1CA4, memberDeleting);
                        fn_122_2234(members + 0x1BF8, memberDeleting);
                        if (members + 0x1BE4 != 0) {
                            fn_27_C7770(members + 0x1BE4, memberDeleting);
                        }
                    }
                }
                if (members + 0xCC != 0) {
                    fn_122_3BC4(members + 0x1BC8, memberDeleting);
                    fn_122_3C20(members + 0x1B88, memberDeleting);
                    fn_122_3C7C(members + 0x1B70, memberDeleting);
                    fn_122_6498(members + 0x1A18, memberDeleting);
                    fn_122_3D5C(members + 0x1880, memberDeleting);
                    fn_122_3DE8(members + 0x1820, memberDeleting);
                    fn_122_57B0(members + 0x176C, memberDeleting);
                    if (members + 0x15A0 != 0) {
                        fn_122_40A0(members + 0x16BC, memberDeleting);
                        fn_122_4124(members + 0x16A8, memberDeleting);
                        if (members + 0x168C != 0) {
                            fn_27_1A4778(members + 0x168C, memberDeleting);
                        }
                        fn_122_4184(members + 0x15E8, memberDeleting);
                        fn_122_42AC(members + 0x15B0, memberDeleting);
                        fn_27_C74E8(members + 0x15A0, memberDeleting);
                    }
                    fn_122_430C(members + 0x14FC, memberDeleting);
                    fn_122_4440(members + 0x14C8, memberDeleting);
                    fn_122_44FC(members + 0x14B0, memberDeleting);
                    fn_122_4558(members + 0x134C, memberDeleting);
                    fn_122_45C4(members + 0x12E4, memberDeleting);
                    fn_122_4624(members + 0x12D8, memberDeleting);
                    fn_122_4684(members + 0x12B0, memberDeleting);
                    fn_122_47CC(members + 0x1104, memberDeleting);
                    fn_122_5998(members + 0xF40, memberDeleting);
                    fn_122_4850(members + 0xEDC, memberDeleting);
                    fn_122_491C(members + 0xEA0, memberDeleting);
                    fn_122_5B54(members + 0xDE8, memberDeleting);
                    fn_122_64F4(members + 0xBDC, memberDeleting);
                    fn_122_4B58(members + 0x9FC, memberDeleting);
                    fn_122_4BC4(members + 0x9CC, memberDeleting);
                    fn_122_4C7C(members + 0x9BC, memberDeleting);
                    fn_122_4CBC(members + 0x9A4, memberDeleting);
                    __dt__16soModuleAccesserFv(members + 0x8C4, memberDeleting);
                    fn_122_4D18(members + 0xCC, memberDeleting);
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