#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_120_12FDC(void*, short);
void* fn_120_12F80(void*, short);
void* fn_120_12F24(void*, short);
void* fn_120_1579C(void*, short);
void* fn_120_12E98(void*, short);
void* fn_120_12E38(void*, short);
void* fn_120_15700(void*, short);
void* fn_120_129B4(void*, short);
void* fn_120_4A30(void*, short);
void* fn_120_1288C(void*, short);
void* fn_120_12780(void*, short);
void* fn_120_125DC(void*, short);
void* fn_120_15628(void*, short);
void* fn_120_1225C(void*, short);
void* fn_120_121E4(void*, short);
void* fn_120_12128(void*, short);
void* fn_120_5A38(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_120_154FC(void*, short);
}

extern "C" void* fn_120_157F8(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_120_12FDC(storage + 0x1560, destroy);
        fn_120_12F80(storage + 0x1520, destroy);
        fn_120_12F24(storage + 0x1508, destroy);
        fn_120_1579C(storage + 0x13B0, destroy);
        fn_120_12E98(storage + 0x1218, destroy);
        fn_120_12E38(storage + 0x11B8, destroy);
        fn_120_15700(storage + 0xFEC, destroy);
        fn_120_129B4(storage + 0xF48, destroy);
        fn_120_4A30(storage + 0xF14, destroy);
        fn_120_1288C(storage + 0xDAC, destroy);
        fn_120_12780(storage + 0xD9C, destroy);
        fn_120_125DC(storage + 0xD2C, destroy);
        fn_120_15628(storage + 0xB1C, destroy);
        fn_120_1225C(storage + 0x93C, destroy);
        fn_120_121E4(storage + 0x90C, destroy);
        fn_120_12128(storage + 0x8FC, destroy);
        fn_120_5A38(storage + 0x8E4, destroy);
        __dt__16soModuleAccesserFv(storage + 0x804, destroy);
        fn_120_154FC(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
