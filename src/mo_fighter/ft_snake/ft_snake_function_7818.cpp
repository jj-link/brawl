#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_122_3860(void*, short);
void* fn_122_3958(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_122_39B4(void*, short);
void* fn_122_3A20(void*, short);
void* fn_122_3AAC(void*, short);
void* fn_122_3B38(void*, short);
void* fn_122_7300(void*, short);
void* fn_122_3C20(void*, short);
void* fn_122_3C7C(void*, short);
void* fn_122_3D5C(void*, short);
void* fn_122_3DE8(void*, short);
void* fn_122_57B0(void*, short);
void* fn_122_6E70(void*, short);
void* fn_122_430C(void*, short);
void* fn_122_4440(void*, short);
void* fn_122_44FC(void*, short);
void* fn_122_4558(void*, short);
void* fn_122_45C4(void*, short);
void* fn_122_4624(void*, short);
void* fn_122_4684(void*, short);
void* fn_122_5998(void*, short);
void* fn_122_4850(void*, short);
void* fn_122_491C(void*, short);
void* fn_122_5B54(void*, short);
void* fn_122_4A58(void*, short);
void* fn_122_4B58(void*, short);
void* fn_122_4BC4(void*, short);
void* fn_122_4C7C(void*, short);
void* fn_122_4CBC(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_122_4D18(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_122_7818(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        if (members + 0x1EFC != 0) {
            if (members + 0x1EFC != 0) {
                fn_122_3860(members + 0x1EFC, static_cast<short>(0));
            }
        }
        if (object != 0) {
            short memberDeleting = -1;
            fn_122_3958(members + 0x1EB4, memberDeleting);
            fn_27_1DBB60(members + 0x1E7C, memberDeleting);
            if (members + 0xCC != 0) {
                if (members + 0x18CC != 0) {
                    fn_122_39B4(members + 0x1D7C, memberDeleting);
                    fn_122_3A20(members + 0x1C50, memberDeleting);
                    fn_122_3AAC(members + 0x1B24, memberDeleting);
                    fn_122_3B38(members + 0x19F8, memberDeleting);
                    fn_122_7300(members + 0x18CC, memberDeleting);
                }
                if (members + 0xCC != 0) {
                    fn_122_3C20(members + 0x1888, memberDeleting);
                    fn_122_3C7C(members + 0x1870, memberDeleting);
                    fn_122_3D5C(members + 0x16D4, memberDeleting);
                    fn_122_3DE8(members + 0x1674, memberDeleting);
                    fn_122_57B0(members + 0x15C0, memberDeleting);
                    fn_122_6E70(members + 0x1400, memberDeleting);
                    fn_122_430C(members + 0x135C, memberDeleting);
                    fn_122_4440(members + 0x1328, memberDeleting);
                    fn_122_44FC(members + 0x1310, memberDeleting);
                    fn_122_4558(members + 0x11AC, memberDeleting);
                    fn_122_45C4(members + 0x1144, memberDeleting);
                    fn_122_4624(members + 0x1138, memberDeleting);
                    fn_122_4684(members + 0x1110, memberDeleting);
                    fn_122_5998(members + 0xF40, memberDeleting);
                    fn_122_4850(members + 0xEDC, memberDeleting);
                    fn_122_491C(members + 0xEA0, memberDeleting);
                    fn_122_5B54(members + 0xDE8, memberDeleting);
                    fn_122_4A58(members + 0xBDC, memberDeleting);
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
