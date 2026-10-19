#include <types.h>
#pragma force_active on

extern "C" void* fn_114_3498(void* object, short deleting);
extern "C" void* fn_114_5B0C(void* p, short n);
void operator delete(void* object);

extern "C" void* fn_114_3428(void* object, short deleting) {
    if (object != 0) {
        fn_114_3498(static_cast<char*>(object) + 8, -1);
        fn_114_5B0C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
