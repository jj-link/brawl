#include <types.h>

extern "C" void* fn_111_A190(void* object, s16 deleting);
extern "C" void* fn_111_A058(void* object, s16 deleting);
extern "C" void* fn_111_39EC(void* object, s16 deleting);

#pragma dont_inline on
extern "C" void* fn_111_A1F0(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_A190(static_cast<u8*>(object) + 0x17C, -1);
        if (object != 0) {
            fn_111_A058(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_A268(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_39EC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_A2C4(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_A268(static_cast<u8*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_A324(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_A2C4(static_cast<u8*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_A384(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_A324(static_cast<u8*>(object) + 0x1C8, -1);
        if (object != 0) {
            fn_111_A1F0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_A3FC(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_39EC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_111_A458(void* object, s16 deleting) {
    if (object != 0) {
        fn_111_A3FC(static_cast<u8*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
#pragma dont_inline reset
