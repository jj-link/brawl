#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_102_1A544(void*, short);
void* fn_102_1A5A0(void*, short);
void* fn_102_1A5FC(void*, short);
void* fn_102_1A658(void*, short);
void* fn_102_1A6E4(void*, short);
void* fn_102_1A744(void*, short);
void* fn_102_1A8D0(void*, short);
void* fn_102_1AB5C(void*, short);
void* fn_102_3DF8(void*, short);
void* fn_102_1AC28(void*, short);
void* fn_102_1AC84(void*, short);
void* fn_102_1ACF0(void*, short);
void* fn_102_1AD9C(void*, short);
void* fn_102_1ADFC(void*, short);
void* fn_102_1AE58(void*, short);
void* fn_102_1AEDC(void*, short);
void* fn_102_3E94(void*, short);
void* fn_102_3EF0(void*, short);
void* fn_102_3F5C(void*, short);
void* fn_102_1AFBC(void*, short);
void* fn_102_1B168(void*, short);
void* fn_102_1B1D4(void*, short);
void* fn_102_3FD0(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_102_1B2D0(void*, short);
}

extern "C" void* fn_102_1A3C4(void* object, short deleting) {
    if (object) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_102_1A544(p + 0x1868, -1);
        fn_102_1A5A0(p + 0x1828, -1);
        fn_102_1A5FC(p + 0x1810, -1);
        fn_102_1A658(p + 0x1674, -1);
        fn_102_1A6E4(p + 0x1620, -1);
        fn_102_1A744(p + 0x156C, -1);
        fn_102_1A8D0(p + 0x13AC, -1);
        fn_102_1AB5C(p + 0x1308, -1);
        fn_102_3DF8(p + 0x12D4, -1);
        fn_102_1AC28(p + 0x12BC, -1);
        fn_102_1AC84(p + 0x1158, -1);
        fn_102_1ACF0(p + 0x10F0, -1);
        fn_102_1AD9C(p + 0x10E4, -1);
        fn_102_1ADFC(p + 0x10BC, -1);
        fn_102_1AE58(p + 0xEEC, -1);
        fn_102_1AEDC(p + 0xE88, -1);
        fn_102_3E94(p + 0xE4C, -1);
        fn_102_3EF0(p + 0xDA4, -1);
        fn_102_3F5C(p + 0xCF0, -1);
        fn_102_1AFBC(p + 0xAE4, -1);
        fn_102_1B168(p + 0x904, -1);
        fn_102_1B1D4(p + 0x8F0, -1);
        fn_102_3FD0(p + 0x8D8, -1);
        __dt__16soModuleAccesserFv(p + 0x7F8, -1);
        fn_102_1B2D0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
