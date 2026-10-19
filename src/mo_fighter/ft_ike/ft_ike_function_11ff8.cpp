#include <stddef.h>
#pragma force_active on

extern "C" void* fn_119_11F98(void* object, short deleting);

extern "C" void* fn_119_11FF8(void* object, short deleting) {
    if (object != 0) {
        fn_119_11F98(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
