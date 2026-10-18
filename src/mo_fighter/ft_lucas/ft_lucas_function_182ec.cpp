#include <types.h>
#pragma force_active on

extern "C" void* fn_114_1834C(void* object, short value);
void operator delete(void* object);

extern "C" void* fn_114_182EC(void* object, short deleting) {
    if (object != 0) {
        fn_114_1834C(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
