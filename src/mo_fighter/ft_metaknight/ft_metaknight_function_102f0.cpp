#include <types.h>
#pragma force_active on

extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_111_1035C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_111_102F0(void* object, short deleting) {
    if (object != 0) {
        fn_27_565F0(static_cast<unsigned char*>(object) + 0xC, -1);
        fn_111_1035C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
