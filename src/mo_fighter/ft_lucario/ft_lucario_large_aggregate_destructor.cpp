void operator delete(void*);
extern "C" void* fn_27_1A65F0(void*, short);
extern "C" void* fn_118_2BB0(void*, short);
extern "C" void* fn_118_2C0C(void*, short);
extern "C" void* fn_118_2C68(void*, short);
extern "C" void* fn_118_2CC4(void*, short);
extern "C" void* fn_118_2D20(void*, short);
extern "C" void* fn_118_2D7C(void*, short);
extern "C" void* fn_118_2E58(void*, short);
extern "C" void* fn_118_2EB4(void*, short);
extern "C" void* fn_118_2F10(void*, short);
extern "C" void* fn_118_2F84(void*, short);
extern "C" void* fn_118_301C(void*, short);
extern "C" void* fn_118_3078(void*, short);
extern "C" void* fn_118_31C8(void*, short);
extern "C" void* fn_118_4E98(void*, short);
extern "C" void* fn_118_4EF8(void*, short);
extern "C" void* fn_118_504C(void*, short);
extern "C" void* fn_118_5BBC(void*, short);
extern "C" void* fn_118_40E8(void*, short);
extern "C" void* fn_118_5C98(void*, short);
extern "C" void* fn_118_5D0C(void*, short);
extern "C" void* fn_118_5DE8(void*, short);
extern "C" void* fn_118_5E44(void*, short);
extern "C" void* fn_118_5EB0(void*, short);
extern "C" void* fn_118_5F5C(void*, short);
extern "C" void* fn_118_5FD0(void*, short);
extern "C" void* fn_118_602C(void*, short);
extern "C" void* fn_118_6088(void*, short);
extern "C" void* fn_118_60E4(void*, short);
extern "C" void* fn_118_6140(void*, short);
extern "C" void* fn_118_61B4(void*, short);
extern "C" void* fn_118_6220(void*, short);
extern "C" void* fn_118_62B0(void*, short);
extern "C" void* fn_118_6340(void*, short);
extern "C" void* fn_118_63C4(void*, short);
extern "C" void* fn_118_6448(void*, short);
extern "C" void* fn_118_43F4(void*, short);
extern "C" void* fn_118_4450(void*, short);
extern "C" void* fn_118_44BC(void*, short);
extern "C" void* fn_118_657C(void*, short);
extern "C" void* fn_118_6940(void*, short);
extern "C" void* fn_118_6A14(void*, short);
extern "C" void* fn_118_6A8C(void*, short);
extern "C" void* fn_118_4694(void*, short);
extern "C" void* __dt__16soModuleAccesserFv(void*, short);
extern "C" void* fn_118_6AE8(void*, short);

extern "C" void* fn_118_28B4(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A65F0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_118_2910(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_118_2BB0(storage + 0xE668, -1);
        fn_118_2C0C(storage + 0xE62C, -1);
        fn_118_2C68(storage + 0xE5C4, -1);
        fn_118_2CC4(storage + 0xE578, -1);
        fn_118_2D20(storage + 0xE424, -1);
        fn_118_2D7C(storage + 0xE314, -1);
        fn_118_2E58(storage + 0xE2CC, -1);
        fn_118_2EB4(storage + 0xE24C, -1);
        fn_118_2F10(storage + 0xE188, -1);
        fn_118_2F84(storage + 0xDE14, -1);
        fn_118_301C(storage + 0xDDE4, -1);
        fn_118_3078(storage + 0xDC40, -1);
        fn_118_31C8(storage + 0x5C24, -1);
        fn_118_4E98(storage + 0x5A40, -1);
        fn_118_4EF8(storage + 0x5738, -1);
        fn_118_504C(storage + 0x48A4, -1);
        fn_118_5BBC(storage + 0x47B0, -1);
        fn_118_40E8(storage + 0x477C, -1);
        fn_118_5C98(storage + 0x4708, -1);
        fn_118_5D0C(storage + 0x3FE4, -1);
        fn_118_5DE8(storage + 0x3FB4, -1);
        fn_118_5E44(storage + 0x3E1C, -1);
        fn_118_5EB0(storage + 0x3DAC, -1);
        fn_118_5F5C(storage + 0x3D14, -1);
        fn_118_5FD0(storage + 0x3CDC, -1);
        fn_118_602C(storage + 0x3CB8, -1);
        fn_118_6088(storage + 0x3C84, -1);
        fn_118_60E4(storage + 0x3C20, -1);
        fn_118_6140(storage + 0x3A70, -1);
        fn_118_61B4(storage + 0x380C, -1);
        fn_118_6220(storage + 0x2DA0, -1);
        fn_118_62B0(storage + 0x29F8, -1);
        fn_118_6340(storage + 0x209C, -1);
        fn_118_63C4(storage + 0x19E0, -1);
        fn_118_6448(storage + 0x196C, -1);
        fn_118_43F4(storage + 0x1930, -1);
        fn_118_4450(storage + 0x1888, -1);
        fn_118_44BC(storage + 0x17D4, -1);
        fn_118_657C(storage + 0x1440, -1);
        fn_118_6940(storage + 0x1180, -1);
        fn_118_6A14(storage + 0x115C, -1);
        fn_118_6A8C(storage + 0xAC8, -1);
        fn_118_4694(storage + 0xAB0, -1);
        __dt__16soModuleAccesserFv(storage + 0x9D0, -1);
        fn_118_6AE8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
