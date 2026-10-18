#include <types.h>
#pragma force_active on

extern "C" void* fn_114_3D68(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_3D08(void* object, short deleting) {
    if (object != 0) {
        fn_114_3D68(static_cast<char*>(object) + 0x38, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
