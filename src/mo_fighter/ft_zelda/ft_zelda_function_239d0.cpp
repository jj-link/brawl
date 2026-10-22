#pragma force_active on
extern "C" void* fn_104_3AF0(void*, short);
extern "C" void* fn_104_3B4C(void*, short);
extern "C" void* fn_104_3BA8(void*, short);
extern "C" void* fn_104_23B68(void*, short);
extern "C" void* fn_104_23BC4(void*, short);
extern "C" void* fn_104_3C04(void*, short);
extern "C" void* fn_104_3D50(void*, short);
extern "C" void* fn_104_3E4C(void*, short);
extern "C" void* fn_104_23C24(void*, short);
extern "C" void* fn_104_4194(void*, short);
extern "C" void* fn_104_42C8(void*, short);
extern "C" void* fn_104_4324(void*, short);
extern "C" void* fn_104_4380(void*, short);
extern "C" void* fn_104_43EC(void*, short);
extern "C" void* fn_104_444C(void*, short);
extern "C" void* fn_104_44AC(void*, short);
extern "C" void* fn_104_4508(void*, short);
extern "C" void* fn_104_458C(void*, short);
extern "C" void* fn_104_4658(void*, short);
extern "C" void* fn_104_4720(void*, short);
extern "C" void* fn_104_23D7C(void*, short);
extern "C" void* fn_104_4894(void*, short);
extern "C" void* fn_104_4900(void*, short);
extern "C" void* fn_104_49B8(void*, short);
extern "C" void* fn_104_49F8(void*, short);
extern "C" void* __dt__16soModuleAccesserFv(void*, short);
extern "C" void* fn_104_23DF4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_239D0(void* object, short deleting) {
    if (object != 0) {
        short flag = -1;
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_104_3AF0(storage + 0x19D0, flag);
        fn_104_3B4C(storage + 0x1990, flag);
        fn_104_3BA8(storage + 0x1978, flag);
        fn_104_23B68(storage + 0x1820, flag);
        fn_104_23BC4(storage + 0x17D0, flag);
        fn_104_3C04(storage + 0x163C, flag);
        fn_104_3D50(storage + 0x15DC, flag);
        fn_104_3E4C(storage + 0x1528, flag);
        fn_104_23C24(storage + 0x1340, flag);
        fn_104_4194(storage + 0x129C, flag);
        fn_104_42C8(storage + 0x1268, flag);
        fn_104_4324(storage + 0x1250, flag);
        fn_104_4380(storage + 0x10EC, flag);
        fn_104_43EC(storage + 0x1084, flag);
        fn_104_444C(storage + 0x1078, flag);
        fn_104_44AC(storage + 0x1050, flag);
        fn_104_4508(storage + 0xE80, flag);
        fn_104_458C(storage + 0xE1C, flag);
        fn_104_4658(storage + 0xDE0, flag);
        fn_104_4720(storage + 0xD28, flag);
        fn_104_23D7C(storage + 0xB1C, flag);
        fn_104_4894(storage + 0x93C, flag);
        fn_104_4900(storage + 0x90C, flag);
        fn_104_49B8(storage + 0x8FC, flag);
        fn_104_49F8(storage + 0x8E4, flag);
        __dt__16soModuleAccesserFv(storage + 0x804, flag);
        fn_104_23DF4(object, flag);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
