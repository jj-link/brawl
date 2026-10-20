#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void* fn_114_77C8(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_7750(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<char*>(object) + 0xf0, -1);
        if (object != 0) {
            fn_114_77C8(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
