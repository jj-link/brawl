#include <types.h>

extern "C" void* fn_111_A590(void* object, s16 deleting);

extern "C" void* fn_111_8D30(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_A590(static_cast<u8*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
