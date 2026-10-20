#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A1B88(void* member, short deleting);
extern "C" void* fn_114_71B0(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_7138(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<char*>(object) + 0x48c, -1);
        if (object != 0) {
            fn_114_71B0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
