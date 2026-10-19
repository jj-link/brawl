#include <types.h>
#pragma force_active on

extern "C" void* fn_114_5C9C(void* object, short deleting);
extern "C" void* fn_114_66E0(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_5C2C(void* object, short deleting) {
    if (object != 0) {
        fn_114_5C9C(static_cast<char*>(object) + 0x2114, -1);
        fn_114_66E0(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
