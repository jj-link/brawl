#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_95_37C8(void*, short);
void* fn_95_3808(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_95_38A4(void*, short);
void* fn_95_3AC8(void*, short);
void* fn_95_3B24(void*, short);
void* fn_95_3B80(void*, short);
void* fn_95_3C0C(void*, short);
void* fn_95_3D08(void*, short);
void* fn_95_3E44(void*, short);
void* fn_95_4154(void*, short);
void* fn_95_4288(void*, short);
void* fn_95_42E4(void*, short);
void* fn_95_4340(void*, short);
void* fn_95_43AC(void*, short);
void* fn_95_440C(void*, short);
void* fn_95_446C(void*, short);
void* fn_95_44C8(void*, short);
void* fn_95_454C(void*, short);
void* fn_95_4618(void*, short);
void* fn_95_46E0(void*, short);
void* fn_95_4754(void*, short);
void* fn_95_4854(void*, short);
void* fn_95_48C0(void*, short);
void* fn_95_4978(void*, short);
void* fn_95_49B8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_95_4A14(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_95_5998(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        if (members + 0x1EFC != 0) {
            if (members + 0x1EFC != 0) {
                fn_95_37C8(members + 0x1EFC, static_cast<short>(0));
            }
        }
        if (object != 0) {
            short memberDeleting = -1;
            fn_95_3808(members + 0x1EB4, memberDeleting);
            fn_27_1DBB60(members + 0x1E7C, memberDeleting);
            if (members + 0xCC != 0) {
                fn_95_38A4(members + 0x18CC, memberDeleting);
                if (members + 0xCC != 0) {
                    fn_95_3AC8(members + 0x1888, memberDeleting);
                    fn_95_3B24(members + 0x1870, memberDeleting);
                    fn_95_3B80(members + 0x16D4, memberDeleting);
                    fn_95_3C0C(members + 0x1674, memberDeleting);
                    fn_95_3D08(members + 0x15C0, memberDeleting);
                    fn_95_3E44(members + 0x1400, memberDeleting);
                    fn_95_4154(members + 0x135C, memberDeleting);
                    fn_95_4288(members + 0x1328, memberDeleting);
                    fn_95_42E4(members + 0x1310, memberDeleting);
                    fn_95_4340(members + 0x11AC, memberDeleting);
                    fn_95_43AC(members + 0x1144, memberDeleting);
                    fn_95_440C(members + 0x1138, memberDeleting);
                    fn_95_446C(members + 0x1110, memberDeleting);
                    fn_95_44C8(members + 0xF40, memberDeleting);
                    fn_95_454C(members + 0xEDC, memberDeleting);
                    fn_95_4618(members + 0xEA0, memberDeleting);
                    fn_95_46E0(members + 0xDE8, memberDeleting);
                    fn_95_4754(members + 0xBDC, memberDeleting);
                    fn_95_4854(members + 0x9FC, memberDeleting);
                    fn_95_48C0(members + 0x9CC, memberDeleting);
                    fn_95_4978(members + 0x9BC, memberDeleting);
                    fn_95_49B8(members + 0x9A4, memberDeleting);
                    __dt__16soModuleAccesserFv(members + 0x8C4, memberDeleting);
                    fn_95_4A14(members + 0xCC, memberDeleting);
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
