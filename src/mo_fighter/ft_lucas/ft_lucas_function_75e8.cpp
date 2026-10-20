#include <types.h>
#pragma force_active on

extern "C" void* fn_27_D2904(void* member, short deleteFlag);
extern "C" void* fn_114_7660(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_75E8(void* object, short deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<char*>(object) + 0x154, -1);
        if (object != 0) {
            fn_114_7660(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
