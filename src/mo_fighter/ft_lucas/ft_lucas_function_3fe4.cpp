#include <types.h>
#pragma force_active on

extern "C" void* fn_27_75E0C(void* object, short deleting);
extern "C" void* fn_27_64930(void* object, short deleting);
extern "C" void* fn_114_208C(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_3FE4(void* object, short deleting) {
    if (object != 0) {
        fn_27_75E0C(static_cast<char*>(object) + 0x4c, -1);
        if (static_cast<char*>(object) + 0x20 != 0) {
            fn_27_64930(static_cast<char*>(object) + 0x20, 0);
        }
        fn_114_208C(static_cast<char*>(object) + 0x14, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
