#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_103_2B88(void*, short);
void* fn_103_2BE4(void*, short);
void* fn_103_2C40(void*, short);
void* fn_103_2C9C(void*, short);
void* fn_103_2CF8(void*, short);
void* fn_103_2D54(void*, short);
void* fn_103_2E30(void*, short);
void* fn_103_2E8C(void*, short);
void* fn_103_2EE8(void*, short);
void* fn_103_2F5C(void*, short);
void* fn_103_2FF4(void*, short);
void* fn_103_3050(void*, short);
void* fn_103_31A0(void*, short);
void* fn_103_53BC(void*, short);
void* fn_103_541C(void*, short);
void* fn_103_5494(void*, short);
void* fn_103_6004(void*, short);
void* fn_103_40B8(void*, short);
void* fn_103_60E0(void*, short);
void* fn_103_6154(void*, short);
void* fn_103_4114(void*, short);
void* fn_103_6230(void*, short);
void* fn_103_629C(void*, short);
void* fn_103_6348(void*, short);
void* fn_103_63BC(void*, short);
void* fn_103_6418(void*, short);
void* fn_103_6474(void*, short);
void* fn_103_64D0(void*, short);
void* fn_103_652C(void*, short);
void* fn_103_65A0(void*, short);
void* fn_103_6618(void*, short);
void* fn_103_6684(void*, short);
void* fn_103_6714(void*, short);
void* fn_103_67A4(void*, short);
void* fn_103_6828(void*, short);
void* fn_103_68AC(void*, short);
void* fn_103_4448(void*, short);
void* fn_103_69E0(void*, short);
void* fn_103_6A4C(void*, short);
void* fn_103_6AC0(void*, short);
void* fn_103_6E84(void*, short);
void* fn_103_6F58(void*, short);
void* fn_103_6FD0(void*, short);
void* fn_103_4704(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* __dt__17PeachEventStorageFv(void*, short);
}

extern "C" void* fn_103_28DC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_103_2B88(members + 0x16854, memberDeleting);
        fn_103_2BE4(members + 0x16818, memberDeleting);
        fn_103_2C40(members + 0x167B0, memberDeleting);
        fn_103_2C9C(members + 0x16764, memberDeleting);
        fn_103_2CF8(members + 0x16610, memberDeleting);
        fn_103_2D54(members + 0x16500, memberDeleting);
        fn_103_2E30(members + 0x164B8, memberDeleting);
        fn_103_2E8C(members + 0x16438, memberDeleting);
        fn_103_2EE8(members + 0x16374, memberDeleting);
        fn_103_2F5C(members + 0x16000, memberDeleting);
        fn_103_2FF4(members + 0x15FD0, memberDeleting);
        fn_103_3050(members + 0x15E2C, memberDeleting);
        fn_103_31A0(members + 0x5F70, memberDeleting);
        fn_103_53BC(members + 0x5D8C, memberDeleting);
        fn_103_541C(members + 0x5A84, memberDeleting);
        fn_103_5494(members + 0x4BE8, memberDeleting);
        fn_103_6004(members + 0x4AF4, memberDeleting);
        fn_103_40B8(members + 0x4AC0, memberDeleting);
        fn_103_60E0(members + 0x4A4C, memberDeleting);
        fn_103_6154(members + 0x4328, memberDeleting);
        fn_103_4114(members + 0x42F8, memberDeleting);
        fn_103_6230(members + 0x4160, memberDeleting);
        fn_103_629C(members + 0x40F0, memberDeleting);
        fn_103_6348(members + 0x4058, memberDeleting);
        fn_103_63BC(members + 0x4020, memberDeleting);
        fn_103_6418(members + 0x3FFC, memberDeleting);
        fn_103_6474(members + 0x3FC8, memberDeleting);
        fn_103_64D0(members + 0x3F64, memberDeleting);
        fn_103_652C(members + 0x3DB4, memberDeleting);
        fn_103_65A0(members + 0x3BBC, memberDeleting);
        fn_103_6618(members + 0x395C, memberDeleting);
        fn_103_6684(members + 0x2EF0, memberDeleting);
        fn_103_6714(members + 0x2B48, memberDeleting);
        fn_103_67A4(members + 0x21EC, memberDeleting);
        fn_103_6828(members + 0x1A10, memberDeleting);
        fn_103_68AC(members + 0x199C, memberDeleting);
        fn_103_4448(members + 0x1960, memberDeleting);
        fn_103_69E0(members + 0x18B8, memberDeleting);
        fn_103_6A4C(members + 0x17D4, memberDeleting);
        fn_103_6AC0(members + 0x1440, memberDeleting);
        fn_103_6E84(members + 0x1180, memberDeleting);
        fn_103_6F58(members + 0x115C, memberDeleting);
        fn_103_6FD0(members + 0xAC8, memberDeleting);
        fn_103_4704(members + 0xAB0, memberDeleting);
        __dt__16soModuleAccesserFv(members + 0x9D0, memberDeleting);
        __dt__17PeachEventStorageFv(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
