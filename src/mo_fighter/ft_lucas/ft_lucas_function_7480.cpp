#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void* fn_114_74F8(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_7480(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<char*>(object) + 0x218, -1);
        if (object != 0) {
            fn_114_74F8(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
