#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_96_7C18(void*, short);
void* fn_96_6C08(void*, short);
void* fn_96_7C74(void*, short);
void* fn_96_6D1C(void*, short);
void* fn_96_2CAF8(void*, short);
void* fn_96_2CB70(void*, short);
void* fn_96_6D7C(void*, short);
void* fn_96_27B8(void*, short);
void* fn_96_6E04(void*, short);
void* fn_96_6E60(void*, short);
void* fn_96_7DE4(void*, short);
void* fn_96_6ECC(void*, short);
void* fn_96_7E44(void*, short);
void* fn_96_2CCC8(void*, short);
void* fn_96_6F2C(void*, short);
void* fn_96_259C(void*, short);
void* fn_96_2530(void*, short);
void* fn_96_24BC(void*, short);
void* fn_96_7EA0(void*, short);
void* fn_96_7040(void*, short);
void* fn_96_70AC(void*, short);
void* fn_96_7124(void*, short);
void* fn_96_2460(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_96_7F18(void*, short);
}

extern "C" void* fn_96_2C978(void* object, short deleting) {
    if (object) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_96_7C18(p + 0x193C, -1);
        fn_96_6C08(p + 0x1924, -1);
        fn_96_7C74(p + 0x1788, -1);
        fn_96_6D1C(p + 0x1728, -1);
        fn_96_2CAF8(p + 0x1644, -1);
        fn_96_2CB70(p + 0x1468, -1);
        fn_96_6D7C(p + 0x13C4, -1);
        fn_96_27B8(p + 0x1390, -1);
        fn_96_6E04(p + 0x1378, -1);
        fn_96_6E60(p + 0x1214, -1);
        fn_96_7DE4(p + 0x11AC, -1);
        fn_96_6ECC(p + 0x11A0, -1);
        fn_96_7E44(p + 0x1178, -1);
        fn_96_2CCC8(p + 0xF18, -1);
        fn_96_6F2C(p + 0xEB4, -1);
        fn_96_259C(p + 0xE78, -1);
        fn_96_2530(p + 0xDD0, -1);
        fn_96_24BC(p + 0xD1C, -1);
        fn_96_7EA0(p + 0xB10, -1);
        fn_96_7040(p + 0x930, -1);
        fn_96_70AC(p + 0x900, -1);
        fn_96_7124(p + 0x8F0, -1);
        fn_96_2460(p + 0x8D8, -1);
        __dt__16soModuleAccesserFv(p + 0x7F8, -1);
        fn_96_7F18(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
