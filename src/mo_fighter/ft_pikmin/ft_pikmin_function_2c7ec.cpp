#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_113_3E1C(void*, short);
void* fn_113_29B4(void*, short);
void* fn_113_2C96C(void*, short);
void* fn_113_3E78(void*, short);
void* fn_113_2C9CC(void*, short);
void* fn_113_2CA2C(void*, short);
void* fn_113_2CBB8(void*, short);
void* fn_113_2DAC(void*, short);
void* fn_113_2EE0(void*, short);
void* fn_113_2CD10(void*, short);
void* fn_113_2F98(void*, short);
void* fn_113_3004(void*, short);
void* fn_113_3064(void*, short);
void* fn_113_30C4(void*, short);
void* fn_113_2CD6C(void*, short);
void* fn_113_317C(void*, short);
void* fn_113_3248(void*, short);
void* fn_113_3310(void*, short);
void* fn_113_2CDF0(void*, short);
void* fn_113_2CE68(void*, short);
void* fn_113_3540(void*, short);
void* fn_113_35F8(void*, short);
void* fn_113_3638(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_113_405C(void*, short);
}

extern "C" void* fn_113_2C7EC(void* object, short deleting) {
    if (object) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_113_3E1C(p + 0x17C4, -1);
        fn_113_29B4(p + 0x17AC, -1);
        fn_113_2C96C(p + 0x1758, -1);
        fn_113_3E78(p + 0x15C4, -1);
        fn_113_2C9CC(p + 0x1544, -1);
        fn_113_2CA2C(p + 0x1490, -1);
        fn_113_2CBB8(p + 0x1298, -1);
        fn_113_2DAC(p + 0x11F4, -1);
        fn_113_2EE0(p + 0x11C0, -1);
        fn_113_2CD10(p + 0x11A8, -1);
        fn_113_2F98(p + 0x1044, -1);
        fn_113_3004(p + 0xFDC, -1);
        fn_113_3064(p + 0xFD0, -1);
        fn_113_30C4(p + 0xFA8, -1);
        fn_113_2CD6C(p + 0xDD8, -1);
        fn_113_317C(p + 0xD74, -1);
        fn_113_3248(p + 0xD38, -1);
        fn_113_3310(p + 0xC80, -1);
        fn_113_2CDF0(p + 0xA74, -1);
        fn_113_2CE68(p + 0x930, -1);
        fn_113_3540(p + 0x900, -1);
        fn_113_35F8(p + 0x8F0, -1);
        fn_113_3638(p + 0x8D8, -1);
        __dt__16soModuleAccesserFv(p + 0x7F8, -1);
        fn_113_405C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
