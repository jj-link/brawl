#include <types.h>
#pragma force_active on

extern "C" void* fn_27_10424(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_20538(void* object, short deleting) {
    if (object != 0) {
        fn_27_10424(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
