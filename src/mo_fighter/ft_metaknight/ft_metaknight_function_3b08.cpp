#include <types.h>
#pragma force_active on

extern "C" void* fn_111_1E48(void* object, s16 deleting);
extern "C" void operator delete(void* object);

#pragma dont_inline on
extern "C" void* fn_111_3B08(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_1E48(static_cast<u8*>(object) + 8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
