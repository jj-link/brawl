#pragma force_active on
extern "C" void* fn_104_3AF0(void*, short);
extern "C" void* fn_104_3B4C(void*, short);
extern "C" void* fn_104_3BA8(void*, short);
extern "C" void* fn_104_3C04(void*, short);
extern "C" void* fn_104_11CE0(void*, short);
extern "C" void* fn_104_3D50(void*, short);
extern "C" void* fn_104_3E4C(void*, short);
extern "C" void* fn_104_11E20(void*, short);
extern "C" void* fn_104_4194(void*, short);
extern "C" void* fn_104_42C8(void*, short);
extern "C" void* fn_104_11F78(void*, short);
extern "C" void* fn_104_4324(void*, short);
extern "C" void* fn_104_4380(void*, short);
extern "C" void* fn_104_43EC(void*, short);
extern "C" void* fn_104_444C(void*, short);
extern "C" void* fn_104_44AC(void*, short);
extern "C" void* fn_104_4508(void*, short);
extern "C" void* fn_104_458C(void*, short);
extern "C" void* fn_104_4658(void*, short);
extern "C" void* fn_104_46B4(void*, short);
extern "C" void* fn_104_4720(void*, short);
extern "C" void* fn_104_4794(void*, short);
extern "C" void* fn_104_4894(void*, short);
extern "C" void* fn_104_4900(void*, short);
extern "C" void* fn_104_49B8(void*, short);
extern "C" void* fn_104_49F8(void*, short);
extern "C" void* __dt__16soModuleAccesserFv(void*, short);
extern "C" void* fn_104_4A54(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_11B3C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short flag = -1;
        fn_104_3AF0(storage + 0x1968, flag);
        fn_104_3B4C(storage + 0x1928, flag);
        fn_104_3BA8(storage + 0x1910, flag);
        fn_104_3C04(storage + 0x1774, flag);
        fn_104_11CE0(storage + 0x16EC, flag);
        fn_104_3D50(storage + 0x1690, flag);
        fn_104_3E4C(storage + 0x15DC, flag);
        fn_104_11E20(storage + 0x13F8, flag);
        fn_104_4194(storage + 0x1354, flag);
        fn_104_42C8(storage + 0x1320, flag);
        fn_104_11F78(storage + 0x12FC, flag);
        fn_104_4324(storage + 0x12E8, flag);
        fn_104_4380(storage + 0x1184, flag);
        fn_104_43EC(storage + 0x111C, flag);
        fn_104_444C(storage + 0x1110, flag);
        fn_104_44AC(storage + 0x10E8, flag);
        fn_104_4508(storage + 0xF18, flag);
        fn_104_458C(storage + 0xEB4, flag);
        fn_104_4658(storage + 0xE78, flag);
        fn_104_46B4(storage + 0xDD0, flag);
        fn_104_4720(storage + 0xD1C, flag);
        fn_104_4794(storage + 0xB10, flag);
        fn_104_4894(storage + 0x930, flag);
        fn_104_4900(storage + 0x900, flag);
        fn_104_49B8(storage + 0x8F0, flag);
        fn_104_49F8(storage + 0x8D8, flag);
        __dt__16soModuleAccesserFv(storage + 0x7F8, flag);
        fn_104_4A54(object, flag);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
