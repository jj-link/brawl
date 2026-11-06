#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_113_3E1C(void*, short);
void* fn_113_29B4(void*, short);
void* fn_113_1A60(void*, short);
void* fn_113_3E78(void*, short);
void* fn_113_29014(void*, short);
void* fn_113_29074(void*, short);
void* fn_113_290EC(void*, short);
void* fn_113_2DAC(void*, short);
void* fn_113_2EE0(void*, short);
void* fn_113_3F8C(void*, short);
void* fn_113_29244(void*, short);
void* fn_113_4000(void*, short);
void* fn_113_2F98(void*, short);
void* fn_113_3004(void*, short);
void* fn_113_3064(void*, short);
void* fn_113_30C4(void*, short);
void* fn_113_292A4(void*, short);
void* fn_113_29328(void*, short);
void* fn_113_317C(void*, short);
void* fn_113_3248(void*, short);
void* fn_113_32A4(void*, short);
void* fn_113_3310(void*, short);
void* fn_113_293AC(void*, short);
void* fn_113_34D4(void*, short);
void* fn_113_3540(void*, short);
void* fn_113_35F8(void*, short);
void* fn_113_3638(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_113_405C(void*, short);
}
extern "C" void* fn_113_28E64(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        short d = -1;
        fn_113_3E1C(p + 0x1D00, d);
        fn_113_29B4(p + 0x1CE8, d);
        fn_113_1A60(p + 0x1C9C, d);
        fn_113_3E78(p + 0x1B04, d);
        fn_113_29014(p + 0x1AA4, d);
        fn_113_29074(p + 0x197C, d);
        fn_113_290EC(p + 0x17AC, d);
        fn_113_2DAC(p + 0x1708, d);
        fn_113_2EE0(p + 0x16D4, d);
        fn_113_3F8C(p + 0x1660, d);
        fn_113_29244(p + 0x1640, d);
        fn_113_4000(p + 0x1610, d);
        fn_113_2F98(p + 0x14AC, d);
        fn_113_3004(p + 0x1444, d);
        fn_113_3064(p + 0x1438, d);
        fn_113_30C4(p + 0x1410, d);
        fn_113_292A4(p + 0x1264, d);
        fn_113_29328(p + 0xF80, d);
        fn_113_317C(p + 0xF1C, d);
        fn_113_3248(p + 0xEE0, d);
        fn_113_32A4(p + 0xE38, d);
        fn_113_3310(p + 0xD84, d);
        fn_113_293AC(p + 0xB10, d);
        fn_113_34D4(p + 0x930, d);
        fn_113_3540(p + 0x900, d);
        fn_113_35F8(p + 0x8F0, d);
        fn_113_3638(p + 0x8D8, d);
        __dt__16soModuleAccesserFv(p + 0x7F8, d);
        fn_113_405C(object, d);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}