#include <types.h>
#pragma force_active on

extern "C" {
extern void* fn_106_35E8(void*, short);
extern void* fn_106_4F24(void*, short);
extern void* fn_27_CD934(void*, short);
extern void __dl__FPv(void*);

extern "C" void* fn_106_4EAC(void* object, short deleteFlag) {
    if (object != nullptr) {
        fn_106_35E8((char*)object + 0xAC, -1);
        fn_106_4F24((char*)object + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
