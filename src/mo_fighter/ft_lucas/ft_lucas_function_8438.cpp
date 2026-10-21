#include <types.h>
#pragma force_active on

extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_114_84EC(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_114_8558(void*, short);
extern "C" void* fn_114_85B4(void*, short);
extern "C" void* fn_114_8610(void*, short);
extern "C" void* fn_114_866C(void*, short);
extern "C" void* fn_114_86C8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_8438(void* object, short deleting) {
    if (object != 0) {
        fn_27_13C90((char*)object + 0x224, -1);
        fn_114_84EC((char*)object + 0x1E8, -1);
        fn_27_21038((char*)object + 0x1D8, -1);
        fn_114_8558((char*)object + 0x1B8, -1);
        fn_114_85B4((char*)object + 0x198, -1);
        fn_114_8610((char*)object + 0x160, -1);
        fn_114_866C((char*)object + 0xC4, -1);
        fn_114_86C8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
