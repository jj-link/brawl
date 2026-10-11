#include <types.h>

extern "C" void* fn_111_A458(void* object, s16 deleting);
extern "C" void* fn_111_A384(void* object, s16 deleting);

#pragma dont_inline on
extern "C" void* fn_111_A4B8(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_A458(static_cast<u8*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_A518(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_A4B8(static_cast<u8*>(object) + 0x204, -1);
        if (object != 0) {
            fn_111_A384(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_A590(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_A518(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
