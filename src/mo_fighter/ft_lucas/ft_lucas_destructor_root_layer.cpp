#include <types.h>

extern "C" void* fn_114_F08C(void* object, short deleting);
extern "C" void* fn_114_EF58(void* object, short deleting);
extern "C" void* fn_114_3A20(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_F0EC(void* object, short deleting) {
    if (object != 0) {
        fn_114_F08C(static_cast<char*>(object) + 0x134, -1);
        if (object != 0) {
            fn_114_EF58(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_114_F164(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_114_3A20(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_114_F1C4(void* object, short deleting) {
    if (object != 0) {
        fn_114_F164(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_114_F224(void* object, short deleting) {
    if (object != 0) {
        fn_114_F1C4(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
