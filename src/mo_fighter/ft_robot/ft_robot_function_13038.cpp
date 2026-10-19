#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_120_12FDC(void*, short);
void* fn_120_12F80(void*, short);
void* fn_120_12F24(void*, short);
void* fn_120_12E98(void*, short);
void* fn_120_12E38(void*, short);
void* fn_120_12DC0(void*, short);
void* fn_120_12C10(void*, short);
void* fn_120_129B4(void*, short);
void* fn_120_4A30(void*, short);
void* fn_120_128F8(void*, short);
void* fn_120_1288C(void*, short);
void* fn_120_12820(void*, short);
void* fn_120_12780(void*, short);
void* fn_120_12724(void*, short);
void* fn_120_126A0(void*, short);
void* fn_120_125DC(void*, short);
void* fn_120_5350(void*, short);
void* fn_120_53AC(void*, short);
void* fn_120_12474(void*, short);
void* fn_120_123FC(void*, short);
void* fn_120_1225C(void*, short);
void* fn_120_121E4(void*, short);
void* fn_120_12128(void*, short);
void* fn_120_5A38(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_120_11F60(void*, short);
}

extern "C" void* fn_120_13038(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_120_12FDC(storage + 0x190C, destroy);
        fn_120_12F80(storage + 0x18CC, destroy);
        fn_120_12F24(storage + 0x18B4, destroy);
        fn_120_12E98(storage + 0x1718, destroy);
        fn_120_12E38(storage + 0x16B8, destroy);
        fn_120_12DC0(storage + 0x1604, destroy);
        fn_120_12C10(storage + 0x1424, destroy);
        fn_120_129B4(storage + 0x1380, destroy);
        fn_120_4A30(storage + 0x134C, destroy);
        fn_120_128F8(storage + 0x1318, destroy);
        fn_120_1288C(storage + 0x11B4, destroy);
        fn_120_12820(storage + 0x114C, destroy);
        fn_120_12780(storage + 0x1140, destroy);
        fn_120_12724(storage + 0x1118, destroy);
        fn_120_126A0(storage + 0xF48, destroy);
        fn_120_125DC(storage + 0xEE4, destroy);
        fn_120_5350(storage + 0xEA8, destroy);
        fn_120_53AC(storage + 0xE00, destroy);
        fn_120_12474(storage + 0xD1C, destroy);
        fn_120_123FC(storage + 0xB10, destroy);
        fn_120_1225C(storage + 0x930, destroy);
        fn_120_121E4(storage + 0x900, destroy);
        fn_120_12128(storage + 0x8F0, destroy);
        fn_120_5A38(storage + 0x8D8, destroy);
        __dt__16soModuleAccesserFv(storage + 0x7F8, destroy);
        fn_120_11F60(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
