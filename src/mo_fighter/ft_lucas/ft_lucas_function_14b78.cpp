#include <types.h>
#pragma force_active on

extern "C" void* fn_114_3B68(void*, short);
extern "C" void* fn_114_3BC4(void*, short);
extern "C" void* fn_114_3C20(void*, short);
extern "C" void* fn_114_3C7C(void*, short);
extern "C" void* fn_114_3D08(void*, short);
extern "C" void* fn_114_3E04(void*, short);
extern "C" void* fn_114_14D1C(void*, short);
extern "C" void* fn_114_41F0(void*, short);
extern "C" void* fn_114_4324(void*, short);
extern "C" void* fn_114_43E4(void*, short);
extern "C" void* fn_114_4440(void*, short);
extern "C" void* fn_114_44AC(void*, short);
extern "C" void* fn_114_450C(void*, short);
extern "C" void* fn_114_456C(void*, short);
extern "C" void* fn_114_14E14(void*, short);
extern "C" void* fn_114_14E88(void*, short);
extern "C" void* fn_114_14F0C(void*, short);
extern "C" void* fn_114_464C(void*, short);
extern "C" void* fn_114_4718(void*, short);
extern "C" void* fn_114_4774(void*, short);
extern "C" void* fn_114_47E0(void*, short);
extern "C" void* fn_114_14FEC(void*, short);
extern "C" void* fn_114_48DC(void*, short);
extern "C" void* fn_114_4948(void*, short);
extern "C" void* fn_114_4A00(void*, short);
extern "C" void* fn_114_4A40(void*, short);
extern "C" void* __dt__16soModuleAccesserFv(void*, short);
extern "C" void* fn_114_4A9C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_14B78(void* object, short deleting) {
    if (object != 0) {
        fn_114_3B68((char*)object + 0x1c98, -1);
        fn_114_3BC4((char*)object + 0x1c58, -1);
        fn_114_3C20((char*)object + 0x1c40, -1);
        fn_114_3C7C((char*)object + 0x1aa4, -1);
        fn_114_3D08((char*)object + 0x1a44, -1);
        fn_114_3E04((char*)object + 0x1990, -1);
        fn_114_14D1C((char*)object + 0x17cc, -1);
        fn_114_41F0((char*)object + 0x1728, -1);
        fn_114_4324((char*)object + 0x16f4, -1);
        fn_114_43E4((char*)object + 0x16dc, -1);
        fn_114_4440((char*)object + 0x1578, -1);
        fn_114_44AC((char*)object + 0x1510, -1);
        fn_114_450C((char*)object + 0x1504, -1);
        fn_114_456C((char*)object + 0x14dc, -1);
        fn_114_14E14((char*)object + 0x1380, -1);
        fn_114_14E88((char*)object + 0x116c, -1);
        fn_114_14F0C((char*)object + 0xf18, -1);
        fn_114_464C((char*)object + 0xeb4, -1);
        fn_114_4718((char*)object + 0xe78, -1);
        fn_114_4774((char*)object + 0xdd0, -1);
        fn_114_47E0((char*)object + 0xd1c, -1);
        fn_114_14FEC((char*)object + 0xb10, -1);
        fn_114_48DC((char*)object + 0x930, -1);
        fn_114_4948((char*)object + 0x900, -1);
        fn_114_4A00((char*)object + 0x8f0, -1);
        fn_114_4A40((char*)object + 0x8d8, -1);
        __dt__16soModuleAccesserFv((char*)object + 0x7f8, -1);
        fn_114_4A9C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}