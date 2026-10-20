#include <types.h>
#pragma force_active on

extern "C" void* fn_27_D2904(void* member, short deleteFlag);
extern "C" void* fn_114_7840(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_77C8(void* object, short deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<char*>(object) + 0xb4, -1);
        if (object != 0) {
            fn_114_7840(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
