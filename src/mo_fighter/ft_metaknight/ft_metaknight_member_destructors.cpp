#include <types.h>

extern "C" void* fn_111_9DA4(void* object, s16 deleting);
extern "C" void* fn_111_9D2C(void* object, s16 deleting);

#pragma dont_inline on
extern "C" void* fn_111_9E04(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_9DA4(static_cast<u8*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_9E64(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_9E04(static_cast<u8*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_9EC4(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_9E64(static_cast<u8*>(object) + 0xEC, -1);
        if (object != 0) {
            fn_111_9D2C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_9F3C(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_9DA4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_9F98(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_9F3C(static_cast<u8*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_9FF8(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_9F98(static_cast<u8*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
