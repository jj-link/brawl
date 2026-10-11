#include <types.h>

extern "C" void* fn_111_9FF8(void* object, s16 deleting);
extern "C" void* fn_111_9EC4(void* object, s16 deleting);
extern "C" void* fn_111_39EC(void* object, s16 deleting);

#pragma dont_inline on
extern "C" void* fn_111_A058(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_9FF8(static_cast<u8*>(object) + 0x134, -1);
        if (object != 0) {
            fn_111_9EC4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_A0D0(void* object, s16 deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_111_39EC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_A130(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_A0D0(static_cast<u8*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_A190(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_A130(static_cast<u8*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
