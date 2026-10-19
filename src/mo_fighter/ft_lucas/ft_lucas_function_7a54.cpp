#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A2524(void* ptr, short arg);
extern "C" void* fn_114_4278(void* p, short flag);
void operator delete(void* object);

extern "C" void* fn_114_7A54(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A2524(static_cast<char*>(object) + 0x10, -1);
        fn_114_4278(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
