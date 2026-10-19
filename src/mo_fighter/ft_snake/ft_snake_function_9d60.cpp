#include <stddef.h>
#pragma force_active on

extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_122_9DCC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_9D60(void* object, short deleting) {
    if (object != NULL) {
        fn_27_565F0(static_cast<unsigned char*>(object) + 0x14, -1);
        fn_122_9DCC(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
