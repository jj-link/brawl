#include <types.h>
#pragma force_active on

extern "C" void* fn_106_8700(void* object, short count);
extern "C" void* fn_106_32C0(void* object, short count);
extern "C" void* fn_106_3320(void* object, short count);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_3248(void* object, short deleteFlag) {
    if (object != nullptr) {
        fn_106_8700(static_cast<char*>(object) + 0xE0, -1);
        fn_106_32C0(static_cast<char*>(object) + 0x30, -1);
        fn_106_3320(object, -1);
        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
