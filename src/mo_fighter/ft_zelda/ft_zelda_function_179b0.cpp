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
void* fn_104_17C5C(void*, short);
void* fn_104_5A4C(void*, short);
void* fn_104_198AC(void*, short);
void* fn_104_19924(void*, short);
void* fn_104_6770(void*, short);
void* fn_104_42C8(void*, short);
void* fn_104_684C(void*, short);
void* fn_104_68C0(void*, short);
void* fn_104_699C(void*, short);
void* fn_104_19A1C(void*, short);
void* fn_104_6A64(void*, short);
void* fn_104_6B10(void*, short);
void* fn_104_6B84(void*, short);
void* fn_104_6BE0(void*, short);
void* fn_104_6C3C(void*, short);
void* fn_104_6C98(void*, short);
void* fn_104_6CF4(void*, short);
void* fn_104_6D68(void*, short);
void* fn_104_6DE0(void*, short);
void* fn_104_19A88(void*, short);
void* fn_104_6EDC(void*, short);
void* fn_104_6F6C(void*, short);
void* fn_104_6FF0(void*, short);
void* fn_104_7074(void*, short);
void* fn_104_4658(void*, short);
void* fn_104_46B4(void*, short);
void* fn_104_4720(void*, short);
void* fn_104_19B18(void*, short);
void* fn_104_756C(void*, short);
void* fn_104_7640(void*, short);
void* fn_104_76B8(void*, short);
void* fn_104_49F8(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_104_7714(void*, short);
}

extern "C" void* fn_104_179B0(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_104_2BD0(storage + 0x1E0C8, destroy);
        fn_104_2C2C(storage + 0x1E08C, destroy);
        fn_104_2C88(storage + 0x1E024, destroy);
        fn_104_2CE4(storage + 0x1DFD8, destroy);
        fn_104_2D40(storage + 0x1DE84, destroy);
        fn_104_2D9C(storage + 0x1DD74, destroy);
        fn_104_2E78(storage + 0x1DD2C, destroy);
        fn_104_2ED4(storage + 0x1DCAC, destroy);
        fn_104_2F30(storage + 0x1DBE8, destroy);
        fn_104_2FA4(storage + 0x1D874, destroy);
        fn_104_303C(storage + 0x1D844, destroy);
        fn_104_3098(storage + 0x1D6A0, destroy);
        fn_104_17C5C(storage + 0x6024, destroy);
        fn_104_5A4C(storage + 0x5E40, destroy);
        fn_104_198AC(storage + 0x5B38, destroy);
        fn_104_19924(storage + 0x4C7C, destroy);
        fn_104_6770(storage + 0x4B88, destroy);
        fn_104_42C8(storage + 0x4B54, destroy);
        fn_104_684C(storage + 0x4AE0, destroy);
        fn_104_68C0(storage + 0x43BC, destroy);
        fn_104_699C(storage + 0x438C, destroy);
        fn_104_19A1C(storage + 0x41C0, destroy);
        fn_104_6A64(storage + 0x4150, destroy);
        fn_104_6B10(storage + 0x40B8, destroy);
        fn_104_6B84(storage + 0x4080, destroy);
        fn_104_6BE0(storage + 0x405C, destroy);
        fn_104_6C3C(storage + 0x4028, destroy);
        fn_104_6C98(storage + 0x3FC4, destroy);
        fn_104_6CF4(storage + 0x3E14, destroy);
        fn_104_6D68(storage + 0x3C1C, destroy);
        fn_104_6DE0(storage + 0x39BC, destroy);
        fn_104_19A88(storage + 0x2F50, destroy);
        fn_104_6EDC(storage + 0x2D38, destroy);
        fn_104_6F6C(storage + 0x23DC, destroy);
        fn_104_6FF0(storage + 0x19E0, destroy);
        fn_104_7074(storage + 0x196C, destroy);
        fn_104_4658(storage + 0x1930, destroy);
        fn_104_46B4(storage + 0x1888, destroy);
        fn_104_4720(storage + 0x17D4, destroy);
        fn_104_19B18(storage + 0x1440, destroy);
        fn_104_756C(storage + 0x1180, destroy);
        fn_104_7640(storage + 0x115C, destroy);
        fn_104_76B8(storage + 0xAC8, destroy);
        fn_104_49F8(storage + 0xAB0, destroy);
        __dt__16soModuleAccesserFv(storage + 0x9D0, destroy);
        fn_104_7714(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}