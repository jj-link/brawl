#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_105_3A80(void*, short);
void* fn_105_3ADC(void*, short);
void* fn_105_1E5C4(void*, short);
void* fn_105_1E620(void*, short);
void* fn_105_3B38(void*, short);
void* fn_105_3BC4(void*, short);
void* fn_105_3CC0(void*, short);
void* fn_105_1E680(void*, short);
void* fn_105_4160(void*, short);
void* fn_105_4294(void*, short);
void* fn_105_42F0(void*, short);
void* fn_105_1E778(void*, short);
void* fn_105_43B8(void*, short);
void* fn_105_4418(void*, short);
void* fn_105_4478(void*, short);
void* fn_105_44D4(void*, short);
void* fn_105_4558(void*, short);
void* fn_105_4624(void*, short);
void* fn_105_4680(void*, short);
void* fn_105_46F4(void*, short);
void* fn_105_47F4(void*, short);
void* fn_105_4860(void*, short);
void* fn_105_4918(void*, short);
void* fn_105_4958(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_105_49B4(void*, short);
}

extern "C" void* fn_105_1E438(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_105_3A80(p + 0x19A0, memberDeleting);
        fn_105_3ADC(p + 0x1988, memberDeleting);
        fn_105_1E5C4(p + 0x1830, memberDeleting);
        fn_105_1E620(p + 0x17E0, memberDeleting);
        fn_105_3B38(p + 0x164C, memberDeleting);
        fn_105_3BC4(p + 0x15EC, memberDeleting);
        fn_105_3CC0(p + 0x1538, memberDeleting);
        fn_105_1E680(p + 0x1368, memberDeleting);
        fn_105_4160(p + 0x12C4, memberDeleting);
        fn_105_4294(p + 0x1290, memberDeleting);
        fn_105_42F0(p + 0x1278, memberDeleting);
        fn_105_1E778(p + 0x10E0, memberDeleting);
        fn_105_43B8(p + 0x1078, memberDeleting);
        fn_105_4418(p + 0x106C, memberDeleting);
        fn_105_4478(p + 0x1044, memberDeleting);
        fn_105_44D4(p + 0xE74, memberDeleting);
        fn_105_4558(p + 0xE10, memberDeleting);
        fn_105_4624(p + 0xDD4, memberDeleting);
        fn_105_4680(p + 0xD1C, memberDeleting);
        fn_105_46F4(p + 0xB10, memberDeleting);
        fn_105_47F4(p + 0x930, memberDeleting);
        fn_105_4860(p + 0x900, memberDeleting);
        fn_105_4918(p + 0x8F0, memberDeleting);
        fn_105_4958(p + 0x8D8, memberDeleting);
        __dt__16soModuleAccesserFv(p + 0x7F8, memberDeleting);
        fn_105_49B4(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
