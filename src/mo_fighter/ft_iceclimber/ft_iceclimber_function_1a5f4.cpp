#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_105_3A80(void*, short);
void* fn_105_3ADC(void*, short);
void* fn_105_3B38(void*, short);
void* fn_105_1A798(void*, short);
void* fn_105_3BC4(void*, short);
void* fn_105_1A810(void*, short);
void* fn_105_1A888(void*, short);
void* fn_105_4160(void*, short);
void* fn_105_4294(void*, short);
void* fn_105_42F0(void*, short);
void* fn_105_434C(void*, short);
void* fn_105_43B8(void*, short);
void* fn_105_1A980(void*, short);
void* fn_105_4478(void*, short);
void* fn_105_52FC(void*, short);
void* fn_105_1A9F4(void*, short);
void* fn_105_1AA78(void*, short);
void* fn_105_4558(void*, short);
void* fn_105_4624(void*, short);
void* fn_105_5370(void*, short);
void* fn_105_4680(void*, short);
void* fn_105_1AAFC(void*, short);
void* fn_105_47F4(void*, short);
void* fn_105_4860(void*, short);
void* fn_105_4918(void*, short);
void* fn_105_4958(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_105_49B4(void*, short);
}

extern "C" void* fn_105_1A5F4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_105_3A80(p + 0x2044, -1);
        fn_105_3ADC(p + 0x202C, -1);
        fn_105_3B38(p + 0x1E90, -1);
        fn_105_1A798(p + 0x1E24, -1);
        fn_105_3BC4(p + 0x1DC8, -1);
        fn_105_1A810(p + 0x1CA0, -1);
        fn_105_1A888(p + 0x1AD4, -1);
        fn_105_4160(p + 0x1A30, -1);
        fn_105_4294(p + 0x19FC, -1);
        fn_105_42F0(p + 0x19E4, -1);
        fn_105_434C(p + 0x1880, -1);
        fn_105_43B8(p + 0x1818, -1);
        fn_105_1A980(p + 0x17D4, -1);
        fn_105_4478(p + 0x17AC, -1);
        fn_105_52FC(p + 0x1650, -1);
        fn_105_1A9F4(p + 0x143C, -1);
        fn_105_1AA78(p + 0xF18, -1);
        fn_105_4558(p + 0xEB4, -1);
        fn_105_4624(p + 0xE78, -1);
        fn_105_5370(p + 0xDD0, -1);
        fn_105_4680(p + 0xD1C, -1);
        fn_105_1AAFC(p + 0xB10, -1);
        fn_105_47F4(p + 0x930, -1);
        fn_105_4860(p + 0x900, -1);
        fn_105_4918(p + 0x8F0, -1);
        fn_105_4958(p + 0x8D8, -1);
        __dt__16soModuleAccesserFv(p + 0x7F8, -1);
        fn_105_49B4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
