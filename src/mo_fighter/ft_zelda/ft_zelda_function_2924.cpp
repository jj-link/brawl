#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_104_2BD0(void*, short);
void* fn_104_2C2C(void*, short);
void* fn_104_2C88(void*, short);
void* fn_104_2CE4(void*, short);
void* fn_104_2D40(void*, short);
void* fn_104_2D9C(void*, short);
void* fn_104_2E78(void*, short);
void* fn_104_2ED4(void*, short);
void* fn_104_2F30(void*, short);
void* fn_104_2FA4(void*, short);
void* fn_104_303C(void*, short);
void* fn_104_3098(void*, short);
void* fn_104_31E8(void*, short);
void* fn_104_5A4C(void*, short);
void* fn_104_5AAC(void*, short);
void* fn_104_5C00(void*, short);
void* fn_104_6770(void*, short);
void* fn_104_42C8(void*, short);
void* fn_104_684C(void*, short);
void* fn_104_68C0(void*, short);
void* fn_104_699C(void*, short);
void* fn_104_69F8(void*, short);
void* fn_104_6A64(void*, short);
void* fn_104_6B10(void*, short);
void* fn_104_6B84(void*, short);
void* fn_104_6BE0(void*, short);
void* fn_104_6C3C(void*, short);
void* fn_104_6C98(void*, short);
void* fn_104_6CF4(void*, short);
void* fn_104_6D68(void*, short);
void* fn_104_6DE0(void*, short);
void* fn_104_6E4C(void*, short);
void* fn_104_6EDC(void*, short);
void* fn_104_6F6C(void*, short);
void* fn_104_6FF0(void*, short);
void* fn_104_7074(void*, short);
void* fn_104_4658(void*, short);
void* fn_104_46B4(void*, short);
void* fn_104_4720(void*, short);
void* fn_104_71A8(void*, short);
void* fn_104_756C(void*, short);
void* fn_104_7640(void*, short);
void* fn_104_76B8(void*, short);
void* fn_104_49F8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_104_7714(void*, short);
}

extern "C" void* fn_104_2924(void* object, short deleting) {
    if (object != 0) {
        // Destroy the embedded module objects in reverse construction order.
        // Their storage belongs to this aggregate and is only released by the
        // deleting form of the destructor (deleting > 0).
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_104_2BD0(members + 0x167DC, memberDeleting);
        fn_104_2C2C(members + 0x167A0, memberDeleting);
        fn_104_2C88(members + 0x16738, memberDeleting);
        fn_104_2CE4(members + 0x166EC, memberDeleting);
        fn_104_2D40(members + 0x16598, memberDeleting);
        fn_104_2D9C(members + 0x16488, memberDeleting);
        fn_104_2E78(members + 0x16440, memberDeleting);
        fn_104_2ED4(members + 0x163C0, memberDeleting);
        fn_104_2F30(members + 0x162FC, memberDeleting);
        fn_104_2FA4(members + 0x15F88, memberDeleting);
        fn_104_303C(members + 0x15F58, memberDeleting);
        fn_104_3098(members + 0x15DB4, memberDeleting);
        fn_104_31E8(members + 0x5E74, memberDeleting);
        fn_104_5A4C(members + 0x5C90, memberDeleting);
        fn_104_5AAC(members + 0x5988, memberDeleting);
        fn_104_5C00(members + 0x4AD8, memberDeleting);
        fn_104_6770(members + 0x49E4, memberDeleting);
        fn_104_42C8(members + 0x49B0, memberDeleting);
        fn_104_684C(members + 0x493C, memberDeleting);
        fn_104_68C0(members + 0x4218, memberDeleting);
        fn_104_699C(members + 0x41E8, memberDeleting);
        fn_104_69F8(members + 0x4050, memberDeleting);
        fn_104_6A64(members + 0x3FE0, memberDeleting);
        fn_104_6B10(members + 0x3F48, memberDeleting);
        fn_104_6B84(members + 0x3F10, memberDeleting);
        fn_104_6BE0(members + 0x3EEC, memberDeleting);
        fn_104_6C3C(members + 0x3EB8, memberDeleting);
        fn_104_6C98(members + 0x3E54, memberDeleting);
        fn_104_6CF4(members + 0x3CA4, memberDeleting);
        fn_104_6D68(members + 0x3AAC, memberDeleting);
        fn_104_6DE0(members + 0x384C, memberDeleting);
        fn_104_6E4C(members + 0x2F50, memberDeleting);
        fn_104_6EDC(members + 0x2D38, memberDeleting);
        fn_104_6F6C(members + 0x23DC, memberDeleting);
        fn_104_6FF0(members + 0x19E0, memberDeleting);
        fn_104_7074(members + 0x196C, memberDeleting);
        fn_104_4658(members + 0x1930, memberDeleting);
        fn_104_46B4(members + 0x1888, memberDeleting);
        fn_104_4720(members + 0x17D4, memberDeleting);
        fn_104_71A8(members + 0x1440, memberDeleting);
        fn_104_756C(members + 0x1180, memberDeleting);
        fn_104_7640(members + 0x115C, memberDeleting);
        fn_104_76B8(members + 0xAC8, memberDeleting);
        fn_104_49F8(members + 0xAB0, memberDeleting);
        __dt__16soModuleAccesserFv(members + 0x9D0, memberDeleting);
        fn_104_7714(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}