#include <types.h>
#pragma force_active on

extern "C" void* fn_114_5D0C(void* object, short deleting);
extern "C" void* fn_114_653C(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_114_64D0(void* object, short deleting) {
    if (object != 0) {
        fn_114_5D0C(static_cast<char*>(object) + 0x7068, -1);
        fn_114_653C(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
