#include <types.h>

extern "C" void* fn_111_98FC(void* object, s16 deleting);
extern "C" void* fn_111_39EC(void* object, s16 deleting);

#pragma dont_inline on
extern "C" void* fn_111_995C(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_98FC(static_cast<u8*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_99BC(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_995C(static_cast<u8*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_9A1C(void* object, s16 deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_111_995C(static_cast<u8*>(object) + 4, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_9A80(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_39EC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_9ADC(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_9A80(static_cast<u8*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
