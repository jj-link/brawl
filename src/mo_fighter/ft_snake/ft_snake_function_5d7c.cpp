#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_122_39B4(void*, short);
void* fn_122_51B0(void*, short);
void* fn_122_3C20(void*, short);
void* fn_122_3C7C(void*, short);
void* fn_122_3D5C(void*, short);
void* fn_122_3DE8(void*, short);
void* fn_122_430C(void*, short);
void* fn_122_4440(void*, short);
void* fn_122_593C(void*, short);
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

extern "C" void* fn_122_5D7C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);

        if (object != 0) {
            if (members + 0xCC != 0) {
                if (members + 0x1478 != 0) {
                    short memberDeleting = -1;
                    fn_122_39B4(members + 0x15AC, memberDeleting);
                    fn_122_51B0(members + 0x147C, memberDeleting);
                }

                if (members + 0xCC != 0) {
                    short memberDeleting = -1;
                    fn_122_3C20(members + 0x1434, memberDeleting);
                    fn_122_3C7C(members + 0x141C, memberDeleting);
                    fn_122_3D5C(members + 0x1280, memberDeleting);
                    fn_122_3DE8(members + 0x1220, memberDeleting);
                    fn_122_430C(members + 0x1178, memberDeleting);
                    fn_122_4440(members + 0x1144, memberDeleting);
                    fn_122_593C(members + 0x1110, memberDeleting);
                    fn_122_4558(members + 0xFAC, memberDeleting);
                    fn_122_45C4(members + 0xF44, memberDeleting);
                    fn_122_4624(members + 0xF38, memberDeleting);
                    fn_122_4684(members + 0xF10, memberDeleting);
                    fn_122_4850(members + 0xEA0, memberDeleting);
                    fn_122_5B54(members + 0xDE8, memberDeleting);
                    fn_122_5BC8(members + 0xBDC, memberDeleting);
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
