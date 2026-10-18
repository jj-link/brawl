#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_105_3A24(void*, short);
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
void* fn_105_44D4(void*, short);
void* fn_105_4558(void*, short);
void* fn_105_4624(void*, short);
void* fn_105_4680(void*, short);
void* fn_105_46F4(void*, short);
void* fn_105_47F4(void*, short);
void* fn_105_4860(void*, short);
void* fn_105_4918(void*, short);
void* fn_105_4958(void*, short);
void* fn_105_49B4(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
}

extern "C" void* fn_105_17A84(void* object, short deleting) {
    if (object) {
        unsigned char* p = (unsigned char*)object;
        fn_105_3A24(p + 0x17FC, -1);
        fn_105_3A80(p + 0x17BC, -1);
        fn_105_3ADC(p + 0x17A4, -1);
        fn_105_3B38(p + 0x1608, -1);
        fn_105_3BC4(p + 0x15A8, -1);
        fn_105_3CC0(p + 0x14F4, -1);
        fn_105_3DFC(p + 0x1334, -1);
        fn_105_4160(p + 0x1290, -1);
        fn_105_4294(p + 0x125C, -1);
        fn_105_42F0(p + 0x1244, -1);
        fn_105_434C(p + 0x10E0, -1);
        fn_105_43B8(p + 0x1078, -1);
        fn_105_4418(p + 0x106C, -1);
        fn_105_4478(p + 0x1044, -1);
        fn_105_44D4(p + 0x0E74, -1);
        fn_105_4558(p + 0x0E10, -1);
        fn_105_4624(p + 0x0DD4, -1);
        fn_105_4680(p + 0x0D1C, -1);
        fn_105_46F4(p + 0x0B10, -1);
        fn_105_47F4(p + 0x0930, -1);
        fn_105_4860(p + 0x0900, -1);
        fn_105_4918(p + 0x08F0, -1);
        fn_105_4958(p + 0x08D8, -1);
        __dt__16soModuleAccesserFv(p + 0x07F8, -1);
        fn_105_49B4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
