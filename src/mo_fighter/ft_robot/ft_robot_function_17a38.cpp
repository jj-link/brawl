#pragma force_active on
extern "C" {
void* fn_120_12F80(void*, short);
void* fn_120_12F24(void*, short);
void* fn_120_12E98(void*, short);
void* fn_120_12E38(void*, short);
void* fn_120_12DC0(void*, short);
void* fn_120_1799C(void*, short);
void* fn_120_129B4(void*, short);
void* fn_120_4A30(void*, short);
void* fn_120_17884(void*, short);
void* fn_120_1288C(void*, short);
void* fn_120_12820(void*, short);
void* fn_120_12780(void*, short);
void* fn_120_12724(void*, short);
void* fn_120_17800(void*, short);
void* fn_120_125DC(void*, short);
void* fn_120_5350(void*, short);
void* fn_120_5418(void*, short);
void* fn_120_17788(void*, short);
void* fn_120_1225C(void*, short);
void* fn_120_12128(void*, short);
void* fn_120_5A38(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_120_11F60(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_120_17A38(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_120_12F80(storage + 0x1ACC, destroy);
        fn_120_12F24(storage + 0x1AB4, destroy);
        fn_120_12E98(storage + 0x1918, destroy);
        fn_120_12E38(storage + 0x18B8, destroy);
        fn_120_12DC0(storage + 0x1804, destroy);
        fn_120_1799C(storage + 0x1638, destroy);
        fn_120_129B4(storage + 0x1594, destroy);
        fn_120_4A30(storage + 0x1560, destroy);
        fn_120_17884(storage + 0x1548, destroy);
        fn_120_1288C(storage + 0x13E4, destroy);
        fn_120_12820(storage + 0x137C, destroy);
        fn_120_12780(storage + 0x1370, destroy);
        fn_120_12724(storage + 0x1348, destroy);
        fn_120_17800(storage + 0xE48, destroy);
        fn_120_125DC(storage + 0xDE4, destroy);
        fn_120_5350(storage + 0xDA8, destroy);
        fn_120_5418(storage + 0xCF0, destroy);
        fn_120_17788(storage + 0xAE4, destroy);
        fn_120_1225C(storage + 0x904, destroy);
        fn_120_12128(storage + 0x8F0, destroy);
        fn_120_5A38(storage + 0x8D8, destroy);
        __dt__16soModuleAccesserFv(storage + 0x7F8, destroy);
        fn_120_11F60(object, destroy);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
