#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_105_3A80(void*, short);
void* fn_105_3ADC(void*, short);
void* fn_105_3B38(void*, short);
void* fn_105_3BC4(void*, short);
void* fn_105_3CC0(void*, short);
void* fn_105_3DFC(void*, short);
void* fn_105_4160(void*, short);
void* fn_105_4294(void*, short);
void* fn_105_42F0(void*, short);
void* fn_105_434C(void*, short);
void* fn_105_43B8(void*, short);
void* fn_105_4418(void*, short);
void* fn_105_4478(void*, short);
void* fn_105_20888(void*, short);
void* fn_105_4558(void*, short);
void* fn_105_4624(void*, short);
void* fn_105_4680(void*, short);
void* fn_105_46F4(void*, short);
void* fn_105_47F4(void*, short);
void* fn_105_4918(void*, short);
void* fn_105_4958(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_105_49B4(void*, short);
}
extern "C" void* fn_105_20720(void* object, short deleting) {
    if (object) {
        unsigned char* p = (unsigned char*)object;
        fn_105_3A80(p + 0x18B0, -1);
        fn_105_3ADC(p + 0x1898, -1);
        fn_105_3B38(p + 0x16FC, -1);
        fn_105_3BC4(p + 0x169C, -1);
        fn_105_3CC0(p + 0x15E8, -1);
        fn_105_3DFC(p + 0x1428, -1);
        fn_105_4160(p + 0x1384, -1);
        fn_105_4294(p + 0x1350, -1);
        fn_105_42F0(p + 0x1338, -1);
        fn_105_434C(p + 0x11D4, -1);
        fn_105_43B8(p + 0x116C, -1);
        fn_105_4418(p + 0x1160, -1);
        fn_105_4478(p + 0x1138, -1);
        fn_105_20888(p + 0xE48, -1);
        fn_105_4558(p + 0xDE4, -1);
        fn_105_4624(p + 0xDA8, -1);
        fn_105_4680(p + 0xCF0, -1);
        fn_105_46F4(p + 0xAE4, -1);
        fn_105_47F4(p + 0x904, -1);
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