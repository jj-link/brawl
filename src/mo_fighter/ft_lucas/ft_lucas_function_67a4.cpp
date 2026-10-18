#include <types.h>
#pragma force_active on

extern "C" void* fn_114_6804(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_114_67A4(void* object, short deleting) {
    if (object != 0) {
        fn_114_6804(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
