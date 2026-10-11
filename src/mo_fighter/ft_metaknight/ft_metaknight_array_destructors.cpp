#include <types.h>

extern "C" void* fn_111_39EC(void* object, s16 deleting);

#pragma dont_inline on
extern "C" void* fn_111_989C(void* object, s16 deleting) {
    if (object) {
        if (object) {
            fn_111_39EC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_98FC(void* object, s16 deleting) {
    if (object) {
        fn_111_989C(static_cast<u8*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
