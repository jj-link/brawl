#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_96_A4D8(void*, short);
void* fn_96_A570(void*, short);
void* fn_96_A5FC(void*, short);
void* fn_96_A688(void*, short);
void* fn_96_A714(void*, short);
void* fn_96_A7A0(void*, short);
void* fn_96_A82C(void*, short);
void* fn_96_A8B8(void*, short);
void* fn_96_A944(void*, short);
void* fn_96_AA2C(void*, short);
void* fn_96_AA98(void*, short);
}

extern "C" void* fn_96_AC10(void* object, short deleting) {
    if (object != 0) {
        char* p = (char*)object;
        fn_96_AA98(p + 0x19B8, -1);
        fn_96_AA2C(p + 0x1894, -1);
        fn_96_A944(p + 0x1768, -1);
        fn_96_A8B8(p + 0x163C, -1);
        fn_96_A82C(p + 0x1510, -1);
        fn_96_A7A0(p + 0x13E4, -1);
        fn_96_A714(p + 0x12B8, -1);
        fn_96_A688(p + 0x118C, -1);
        fn_96_A5FC(p + 0x1060, -1);
        fn_96_A570(p + 0x0F34, -1);
        fn_96_A4D8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
