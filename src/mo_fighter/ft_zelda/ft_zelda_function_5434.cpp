#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_104_3804(void*, short);
void* fn_104_3844(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_104_38E0(void*, short);
void* fn_104_394C(void*, short);
void* fn_104_39D8(void*, short);
void* fn_104_3A64(void*, short);
void* fn_104_50D8(void*, short);
void* fn_104_3B4C(void*, short);
void* fn_104_3BA8(void*, short);
void* fn_104_3C04(void*, short);
void* fn_104_3D50(void*, short);
void* fn_104_3E4C(void*, short);
void* fn_104_5648(void*, short);
void* fn_104_4194(void*, short);
void* fn_104_42C8(void*, short);
void* fn_104_4324(void*, short);
void* fn_104_4380(void*, short);
void* fn_104_43EC(void*, short);
void* fn_104_444C(void*, short);
void* fn_104_44AC(void*, short);
void* fn_104_4508(void*, short);
void* fn_104_458C(void*, short);
void* fn_104_4658(void*, short);
void* fn_104_4720(void*, short);
void* fn_104_4794(void*, short);
void* fn_104_4894(void*, short);
void* fn_104_4900(void*, short);
void* fn_104_49B8(void*, short);
void* fn_104_49F8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_104_4A54(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_104_5434(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        if (members + 0x1EFC != 0) {
            if (members + 0x1EFC != 0) {
                fn_104_3804(members + 0x1EFC, static_cast<short>(0));
            }
        }
        if (object != 0) {
            short memberDeleting = -1;
            fn_104_3844(members + 0x1EB4, memberDeleting);
            fn_27_1DBB60(members + 0x1E7C, memberDeleting);
            if (members + 0xCC != 0) {
                if (members + 0x18CC != 0) {
                    fn_104_38E0(members + 0x1D7C, memberDeleting);
                    fn_104_394C(members + 0x1C50, memberDeleting);
                    fn_104_39D8(members + 0x1B24, memberDeleting);
                    fn_104_3A64(members + 0x19F8, memberDeleting);
                    fn_104_50D8(members + 0x18CC, memberDeleting);
                }
                if (members + 0xCC != 0) {
                    fn_104_3B4C(members + 0x1888, memberDeleting);
                    fn_104_3BA8(members + 0x1870, memberDeleting);
                    fn_104_3C04(members + 0x16D4, memberDeleting);
                    fn_104_3D50(members + 0x1674, memberDeleting);
                    fn_104_3E4C(members + 0x15C0, memberDeleting);
                    fn_104_5648(members + 0x1400, memberDeleting);
                    fn_104_4194(members + 0x135C, memberDeleting);
                    fn_104_42C8(members + 0x1328, memberDeleting);
                    fn_104_4324(members + 0x1310, memberDeleting);
                    fn_104_4380(members + 0x11AC, memberDeleting);
                    fn_104_43EC(members + 0x1144, memberDeleting);
                    fn_104_444C(members + 0x1138, memberDeleting);
                    fn_104_44AC(members + 0x1110, memberDeleting);
                    fn_104_4508(members + 0xF40, memberDeleting);
                    fn_104_458C(members + 0xEDC, memberDeleting);
                    fn_104_4658(members + 0xEA0, memberDeleting);
                    fn_104_4720(members + 0xDE8, memberDeleting);
                    fn_104_4794(members + 0xBDC, memberDeleting);
                    fn_104_4894(members + 0x9FC, memberDeleting);
                    fn_104_4900(members + 0x9CC, memberDeleting);
                    fn_104_49B8(members + 0x9BC, memberDeleting);
                    fn_104_49F8(members + 0x9A4, memberDeleting);
                    __dt__16soModuleAccesserFv(members + 0x8C4, memberDeleting);
                    fn_104_4A54(members + 0xCC, memberDeleting);
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
