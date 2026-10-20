#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A1FE4(void* object, short value);
extern "C" void* fn_114_7480(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_7408(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1FE4(static_cast<char*>(object) + 0x244, -1);
        if (object != 0) {
            fn_114_7480(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
