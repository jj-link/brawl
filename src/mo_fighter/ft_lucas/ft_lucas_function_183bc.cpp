#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_114_3A60(void*, short);
void* fn_114_3AA0(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_114_5680(void*, short);
void* fn_114_3B68(void*, short);
void* fn_114_3BC4(void*, short);
void* fn_114_3C20(void*, short);
void* fn_114_3C7C(void*, short);
void* fn_114_3D08(void*, short);
void* fn_114_3E04(void*, short);
void* fn_114_3FE4(void*, short);
void* fn_114_4068(void*, short);
void* fn_114_5A38(void*, short);
void* fn_114_40C8(void*, short);
void* fn_114_3D68(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_114_41F0(void*, short);
void* fn_114_4324(void*, short);
void* fn_114_43E4(void*, short);
void* fn_27_6A3D8(void*, short);
void* fn_27_199E3C(void*, short);
void* fn_114_44AC(void*, short);
void* fn_114_450C(void*, short);
void* fn_114_456C(void*, short);
void* fn_114_45C8(void*, short);
void* fn_114_464C(void*, short);
void* fn_114_4718(void*, short);
void* fn_114_47E0(void*, short);
void* fn_114_5A94(void*, short);
void* fn_114_48DC(void*, short);
void* fn_114_4948(void*, short);
void* fn_114_4A00(void*, short);
void* fn_114_4A40(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_114_4A9C(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_114_183BC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        // Distinct inlined lifetime layers retain their own receiver guards.
        if (members + 0x1F50 != 0) {
            if (members + 0x1F50 != 0) {
                fn_114_3A60(members + 0x1F50, static_cast<short>(0));
            }
        }
        if (object != 0) {
            short memberDeleting = -1;
            fn_114_3AA0(members + 0x1F08, memberDeleting);
            fn_27_1DBB60(members + 0x1ED0, memberDeleting);
            if (members + 0xCC != 0) {
                fn_114_5680(members + 0x1920, memberDeleting);
                if (members + 0xCC != 0) {
                    fn_114_3B68(members + 0x1904, memberDeleting);
                    fn_114_3BC4(members + 0x18C4, memberDeleting);
                    fn_114_3C20(members + 0x18AC, memberDeleting);
                    fn_114_3C7C(members + 0x1710, memberDeleting);
                    fn_114_3D08(members + 0x16B0, memberDeleting);
                    fn_114_3E04(members + 0x15FC, memberDeleting);
                    if (members + 0x1434 != 0) {
                        fn_114_3FE4(members + 0x154C, memberDeleting);
                        fn_114_4068(members + 0x1538, memberDeleting);
                        fn_114_5A38(members + 0x1528, memberDeleting);
                        fn_114_40C8(members + 0x1484, memberDeleting);
                        if (members + 0x1444 != 0) {
                            fn_114_3D68(members + 0x1460, memberDeleting);
                        }
                        fn_27_C74E8(members + 0x1434, static_cast<short>(-1));
                    }
                    fn_114_41F0(members + 0x1390, memberDeleting);
                    fn_114_4324(members + 0x135C, memberDeleting);
                    fn_114_43E4(members + 0x1344, memberDeleting);
                    if (members + 0x11AC != 0) {
                        fn_27_6A3D8(members + 0x12F0, memberDeleting);
                        fn_27_199E3C(members + 0x11AC, memberDeleting);
                    }
                    fn_114_44AC(members + 0x1144, memberDeleting);
                    fn_114_450C(members + 0x1138, memberDeleting);
                    fn_114_456C(members + 0x1110, memberDeleting);
                    fn_114_45C8(members + 0xF40, memberDeleting);
                    fn_114_464C(members + 0xEDC, memberDeleting);
                    fn_114_4718(members + 0xEA0, memberDeleting);
                    fn_114_47E0(members + 0xDE8, memberDeleting);
                    fn_114_5A94(members + 0xBDC, memberDeleting);
                    fn_114_48DC(members + 0x9FC, memberDeleting);
                    fn_114_4948(members + 0x9CC, memberDeleting);
                    fn_114_4A00(members + 0x9BC, memberDeleting);
                    fn_114_4A40(members + 0x9A4, memberDeleting);
                    __dt__16soModuleAccesserFv(members + 0x8C4, memberDeleting);
                    fn_114_4A9C(members + 0xCC, memberDeleting);
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