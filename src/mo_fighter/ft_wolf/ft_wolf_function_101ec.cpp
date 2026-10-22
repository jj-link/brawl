#pragma force_active on
extern "C" void* fn_125_4D18(void*, short);
extern "C" void* fn_125_39FC(void*, short);
extern "C" void* fn_125_3A58(void*, short);
extern "C" void* fn_125_3AE4(void*, short);
extern "C" void* fn_125_10354(void*, short);
extern "C" void* fn_125_3EF0(void*, short);
extern "C" void* fn_125_4024(void*, short);
extern "C" void* fn_125_4080(void*, short);
extern "C" void* fn_125_40DC(void*, short);
extern "C" void* fn_125_4148(void*, short);
extern "C" void* fn_125_41A8(void*, short);
extern "C" void* fn_125_4208(void*, short);
extern "C" void* fn_125_5570(void*, short);
extern "C" void* fn_125_4264(void*, short);
extern "C" void* fn_125_4330(void*, short);
extern "C" void* fn_125_438C(void*, short);
extern "C" void* fn_125_104A8(void*, short);
extern "C" void* fn_125_44E4(void*, short);
extern "C" void* fn_125_4550(void*, short);
extern "C" void* fn_125_4608(void*, short);
extern "C" void* fn_125_4648(void*, short);
extern "C" void* fn_125_46A4(void*, short);
extern "C" void* __dt__16soModuleAccesserFv(void*, short);
extern void operator delete(void*);

extern "C" void* fn_125_101EC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_125_4D18(storage + 0x1714, -1);
        fn_125_39FC(storage + 0x16F8, -1);
        fn_125_3A58(storage + 0x155C, -1);
        fn_125_3AE4(storage + 0x14FC, -1);
        fn_125_10354(storage + 0x1334, -1);
        fn_125_3EF0(storage + 0x1290, -1);
        fn_125_4024(storage + 0x125C, -1);
        fn_125_4080(storage + 0x1244, -1);
        fn_125_40DC(storage + 0x10E0, -1);
        fn_125_4148(storage + 0x1078, -1);
        fn_125_41A8(storage + 0x106C, -1);
        fn_125_4208(storage + 0x1044, -1);
        fn_125_5570(storage + 0xE74, -1);
        fn_125_4264(storage + 0xE10, -1);
        fn_125_4330(storage + 0xDD4, -1);
        fn_125_438C(storage + 0xD1C, -1);
        fn_125_104A8(storage + 0xB10, -1);
        fn_125_44E4(storage + 0x930, -1);
        fn_125_4550(storage + 0x900, -1);
        fn_125_4608(storage + 0x8F0, -1);
        fn_125_4648(storage + 0x8D8, -1);
        __dt__16soModuleAccesserFv(storage + 0x7F8, -1);
        fn_125_46A4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
