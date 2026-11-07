#include <types.h>
#pragma force_active on

extern "C" void* fn_114_22A0(void*, short);
extern "C" void* fn_114_2464(void*, short);
extern "C" void* fn_114_252C(void*, short);
extern "C" void* fn_114_25B8(void*, short);
extern "C" void* fn_114_2644(void*, short);
extern "C" void* fn_114_26D0(void*, short);
extern "C" void* fn_114_275C(void*, short);
extern "C" void* fn_114_27E8(void*, short);
extern "C" void* fn_114_2874(void*, short);
extern "C" void* fn_114_2900(void*, short);
extern "C" void* fn_114_298C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_21C8(void* object, short deleting) {
    if (object != 0) {
        fn_114_22A0((char*)object + 0x14C8, -1);
        fn_114_2464((char*)object + 0x13A4, -1);
        fn_114_252C((char*)object + 0x1278, -1);
        fn_114_25B8((char*)object + 0x114C, -1);
        fn_114_2644((char*)object + 0x1020, -1);
        fn_114_26D0((char*)object + 0xEF4, -1);
        fn_114_275C((char*)object + 0xDC8, -1);
        fn_114_27E8((char*)object + 0xC9C, -1);
        fn_114_2874((char*)object + 0xB70, -1);
        fn_114_2900((char*)object + 0xA44, -1);
        fn_114_298C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
