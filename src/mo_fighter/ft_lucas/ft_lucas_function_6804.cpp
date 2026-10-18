#include <types.h>
#pragma force_active on

extern "C" void fn_114_6864(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_114_6804(void* object, short deleting) {
    if (object != 0) {
        fn_114_6864(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
