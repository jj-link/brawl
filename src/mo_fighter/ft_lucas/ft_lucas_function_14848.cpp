#include <types.h>
#pragma force_active on

extern "C" void* fn_114_148B8(void* object, short deleting);
extern "C" void* fn_114_14B78(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_14848(void* object, short deleting) {
    if (object != 0) {
        fn_114_148B8(static_cast<char*>(object) + 0x1cb4, -1);
        fn_114_14B78(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
