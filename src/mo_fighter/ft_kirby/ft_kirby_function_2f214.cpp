#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_96_7C18(void*, short);
void* fn_96_6C08(void*, short);
void* fn_96_7C74(void*, short);
void* fn_96_6D1C(void*, short);
void* fn_96_2F364(void*, short);
void* fn_96_6D7C(void*, short);
void* fn_96_27B8(void*, short);
void* fn_96_6E04(void*, short);
void* fn_96_6E60(void*, short);
void* fn_96_7DE4(void*, short);
void* fn_96_6ECC(void*, short);
void* fn_96_7E44(void*, short);
void* fn_96_6F2C(void*, short);
void* fn_96_24BC(void*, short);
void* fn_96_7EA0(void*, short);
void* fn_96_7040(void*, short);
void* fn_96_70AC(void*, short);
void* fn_96_7124(void*, short);
void* fn_96_2460(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_96_7F18(void*, short);
}

extern "C" void* fn_96_2F214(void* object, short deleting) {
    if (object) {
        char* p = (char*)object;
        fn_96_7C18(p + 0x151c, -1);
        fn_96_6C08(p + 0x1504, -1);
        fn_96_7C74(p + 0x1368, -1);
        fn_96_6D1C(p + 0x1308, -1);
        fn_96_2F364(p + 0x1134, -1);
        fn_96_6D7C(p + 0x1090, -1);
        fn_96_27B8(p + 0x105c, -1);
        fn_96_6E04(p + 0x1044, -1);
        fn_96_6E60(p + 0x0ee0, -1);
        fn_96_7DE4(p + 0x0e78, -1);
        fn_96_6ECC(p + 0x0e6c, -1);
        fn_96_7E44(p + 0x0e44, -1);
        fn_96_6F2C(p + 0x0dd4, -1);
        fn_96_24BC(p + 0x0d1c, -1);
        fn_96_7EA0(p + 0x0b10, -1);
        fn_96_7040(p + 0x0930, -1);
        fn_96_70AC(p + 0x0900, -1);
        fn_96_7124(p + 0x08f0, -1);
        fn_96_2460(p + 0x08d8, -1);
        __dt__16soModuleAccesserFv(p + 0x07f8, -1);
        fn_96_7F18(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
