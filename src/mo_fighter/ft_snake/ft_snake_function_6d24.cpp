#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_122_3C20(void*, short);
void* fn_122_3C7C(void*, short);
void* fn_122_3D5C(void*, short);
void* fn_122_3DE8(void*, short);
void* fn_122_6E70(void*, short);
void* fn_122_4440(void*, short);
void* fn_122_4558(void*, short);
void* fn_122_45C4(void*, short);
void* fn_122_4624(void*, short);
void* fn_122_4684(void*, short);
void* fn_122_4850(void*, short);
void* fn_122_5B54(void*, short);
void* fn_122_4B58(void*, short);
void* fn_122_4BC4(void*, short);
void* fn_122_4C7C(void*, short);
void* fn_122_4CBC(void*, short);
void* fn_122_4D18(void*, short);
void* fn_27_1D81C8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
}

extern "C" void* fn_122_6D24(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            unsigned char* members = static_cast<unsigned char*>(object);
            short memberDeleting = -1;
            if (members + 0xCC != 0) {
                if (members + 0xCC != 0) {
                    fn_122_3C20(members + 0x1318, memberDeleting);
                    fn_122_3C7C(members + 0x1300, memberDeleting);
                    fn_122_3D5C(members + 0x1164, memberDeleting);
                    fn_122_3DE8(members + 0x1104, memberDeleting);
                    fn_122_6E70(members + 0xF44, memberDeleting);
                    fn_122_4440(members + 0xF0C, memberDeleting);
                    fn_122_4558(members + 0xDA4, memberDeleting);
                    fn_122_45C4(members + 0xD3C, memberDeleting);
                    fn_122_4624(members + 0xD30, memberDeleting);
                    fn_122_4684(members + 0xD08, memberDeleting);
                    fn_122_4850(members + 0xC98, memberDeleting);
                    fn_122_5B54(members + 0xBE0, memberDeleting);
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
