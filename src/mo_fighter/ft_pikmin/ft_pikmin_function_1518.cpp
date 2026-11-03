#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_113_17B8(void*, short);
void* fn_113_1814(void*, short);
void* fn_113_1870(void*, short);
void* fn_113_18CC(void*, short);
void* fn_113_1928(void*, short);
void* fn_113_1984(void*, short);
void* fn_113_1A60(void*, short);
void* fn_113_1ABC(void*, short);
void* fn_113_1B18(void*, short);
void* fn_113_1B8C(void*, short);
void* fn_113_1C24(void*, short);
void* fn_113_1C80(void*, short);
void* fn_113_1DD0(void*, short);
void* fn_113_4830(void*, short);
void* fn_113_4890(void*, short);
void* fn_113_4908(void*, short);
void* fn_113_5478(void*, short);
void* fn_113_2EE0(void*, short);
void* fn_113_3F8C(void*, short);
void* fn_113_5554(void*, short);
void* fn_113_4000(void*, short);
void* fn_113_5630(void*, short);
void* fn_113_569C(void*, short);
void* fn_113_5748(void*, short);
void* fn_113_57BC(void*, short);
void* fn_113_5818(void*, short);
void* fn_113_5874(void*, short);
void* fn_113_3120(void*, short);
void* fn_113_58D0(void*, short);
void* fn_113_5944(void*, short);
void* fn_113_59B0(void*, short);
void* fn_113_5A40(void*, short);
void* fn_113_5AD0(void*, short);
void* fn_113_5B54(void*, short);
void* fn_113_5BD8(void*, short);
void* fn_113_3248(void*, short);
void* fn_113_32A4(void*, short);
void* fn_113_3310(void*, short);
void* fn_113_5D0C(void*, short);
void* fn_113_6008(void*, short);
void* fn_113_60DC(void*, short);
void* fn_113_6154(void*, short);
void* fn_113_3638(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_113_61B0(void*, short);
}

extern "C" void* fn_113_1518(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_113_17B8(storage + 0x1DE80, destroy);
        fn_113_1814(storage + 0x1DE44, destroy);
        fn_113_1870(storage + 0x1DDDC, destroy);
        fn_113_18CC(storage + 0x1DD90, destroy);
        fn_113_1928(storage + 0x1DC3C, destroy);
        fn_113_1984(storage + 0x1DB2C, destroy);
        fn_113_1A60(storage + 0x1DAE4, destroy);
        fn_113_1ABC(storage + 0x1DA64, destroy);
        fn_113_1B18(storage + 0x1D9A0, destroy);
        fn_113_1B8C(storage + 0x1D62C, destroy);
        fn_113_1C24(storage + 0x1D5FC, destroy);
        fn_113_1C80(storage + 0x1D458, destroy);
        fn_113_1DD0(storage + 0x5BE0, destroy);
        fn_113_4830(storage + 0x59FC, destroy);
        fn_113_4890(storage + 0x56F4, destroy);
        fn_113_4908(storage + 0x4880, destroy);
        fn_113_5478(storage + 0x478C, destroy);
        fn_113_2EE0(storage + 0x4758, destroy);
        fn_113_3F8C(storage + 0x46E4, destroy);
        fn_113_5554(storage + 0x3FC0, destroy);
        fn_113_4000(storage + 0x3F90, destroy);
        fn_113_5630(storage + 0x3C8C, destroy);
        fn_113_569C(storage + 0x3C1C, destroy);
        fn_113_5748(storage + 0x3B84, destroy);
        fn_113_57BC(storage + 0x3B4C, destroy);
        fn_113_5818(storage + 0x3B28, destroy);
        fn_113_5874(storage + 0x3AF4, destroy);
        fn_113_3120(storage + 0x3A90, destroy);
        fn_113_58D0(storage + 0x38E0, destroy);
        fn_113_5944(storage + 0x367C, destroy);
        fn_113_59B0(storage + 0x2C10, destroy);
        fn_113_5A40(storage + 0x29F8, destroy);
        fn_113_5AD0(storage + 0x209C, destroy);
        fn_113_5B54(storage + 0x19E0, destroy);
        fn_113_5BD8(storage + 0x196C, destroy);
        fn_113_3248(storage + 0x1930, destroy);
        fn_113_32A4(storage + 0x1888, destroy);
        fn_113_3310(storage + 0x17D4, destroy);
        fn_113_5D0C(storage + 0x1440, destroy);
        fn_113_6008(storage + 0x1180, destroy);
        fn_113_60DC(storage + 0x115C, destroy);
        fn_113_6154(storage + 0xAC8, destroy);
        fn_113_3638(storage + 0xAB0, destroy);
        __dt__16soModuleAccesserFv(storage + 0x9D0, destroy);
        fn_113_61B0(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
