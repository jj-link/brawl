#pragma force_active on
#include <so/so_module_accesser.h>
void operator delete(void*);
extern "C" {
void* fn_96_7C18(void*, short);
void* fn_96_6C08(void*, short);
void* fn_96_6C64(void*, short);
void* fn_96_7C74(void*, short);
void* fn_96_6D1C(void*, short);
void* fn_96_25B6C(void*, short);
void* fn_96_6D7C(void*, short);
void* fn_96_27B8(void*, short);
void* fn_96_6E04(void*, short);
void* fn_96_6E60(void*, short);
void* fn_96_7DE4(void*, short);
void* fn_96_6ECC(void*, short);
void* fn_96_7E44(void*, short);
void* fn_96_6F2C(void*, short);
void* fn_96_24BC(void*, short);
void* fn_96_25C64(void*, short);
void* fn_96_7040(void*, short);
void* fn_96_70AC(void*, short);
void* fn_96_7124(void*, short);
void* fn_96_2460(void*, short);
void* fn_96_7F18(void*, short);
}
extern "C" void* fn_96_25A10(void* object, short deleting) {
    if (object) {
        char* p = (char*)object;
        fn_96_7C18(p + 0x1660, -1);
        fn_96_6C08(p + 0x1648, -1);
        fn_96_6C64(p + 0x14f0, -1);
        fn_96_7C74(p + 0x1358, -1);
        fn_96_6D1C(p + 0x12f8, -1);
        fn_96_25B6C(p + 0x1134, -1);
        fn_96_6D7C(p + 0x1090, -1);
        fn_96_27B8(p + 0x105c, -1);
        fn_96_6E04(p + 0x1044, -1);
        fn_96_6E60(p + 0xee0, -1);
        fn_96_7DE4(p + 0xe78, -1);
        fn_96_6ECC(p + 0xe6c, -1);
        fn_96_7E44(p + 0xe44, -1);
        fn_96_6F2C(p + 0xdd4, -1);
        fn_96_24BC(p + 0xd1c, -1);
        fn_96_25C64(p + 0xb10, -1);
        fn_96_7040(p + 0x930, -1);
        fn_96_70AC(p + 0x900, -1);
        fn_96_7124(p + 0x8f0, -1);
        fn_96_2460(p + 0x8d8, -1);
        reinterpret_cast<soModuleAccesser*>(p + 0x7f8)->soModuleAccesser::~soModuleAccesser();
        fn_96_7F18(object, -1);
        if (deleting > 0) operator delete(object);
    }
    return object;
}