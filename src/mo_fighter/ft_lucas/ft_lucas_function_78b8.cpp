#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A1E70(void* object, short value);
extern "C" void* fn_114_7928(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_78B8(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<char*>(object) + 0x1C, -1);
        fn_114_7928(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
