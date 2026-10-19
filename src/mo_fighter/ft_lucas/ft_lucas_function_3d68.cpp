#include <types.h>
#pragma force_active on

extern "C" void* fn_114_3DC4(void* p, s16 flags);
void operator delete(void* object);

extern "C" void* fn_114_3D68(void* object, short deleting) {
    if (object != 0) {
        fn_114_3DC4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
