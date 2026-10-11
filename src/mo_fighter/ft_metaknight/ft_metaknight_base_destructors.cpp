#include <types.h>

extern "C" void* fn_111_9ADC(void* object, s16 deleting);
extern "C" void* fn_111_9A1C(void* object, s16 deleting);
extern "C" void* fn_111_39EC(void* object, s16 deleting);

#pragma dont_inline on
extern "C" void* fn_111_9B3C(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_9ADC(static_cast<u8*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_9B9C(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_9B3C(static_cast<u8*>(object) + 0x60, -1);
        fn_111_9A1C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_9C0C(void* object, s16 deleting) {
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

extern "C" void* fn_111_9C6C(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_9C0C(static_cast<u8*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_9CCC(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_9C6C(static_cast<u8*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_9D2C(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_9CCC(static_cast<u8*>(object) + 0x94, -1);
        if (object != 0) {
            fn_111_9B9C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_9DA4(void* object, s16 deleting) {
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
#pragma dont_inline reset
