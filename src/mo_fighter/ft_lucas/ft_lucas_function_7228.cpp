#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A18A0(void*, short);
extern "C" void* fn_114_72A0(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_7228(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A18A0(static_cast<char*>(object) + 0x354, -1);
        if (object != 0) {
            fn_114_72A0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
