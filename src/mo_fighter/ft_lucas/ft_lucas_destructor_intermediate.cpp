#include <types.h>

extern "C" void* fn_114_EBD0(void* object, short deleting);
extern "C" void* fn_114_EAB0(void* object, short deleting);
extern "C" void* fn_114_3A20(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_EC30(void* object, short deleting) {
    if (object != 0) {
        fn_114_EBD0(static_cast<char*>(object) + 0x60, -1);
        fn_114_EAB0(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_114_ECA0(void* object, short deleting) {
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

extern "C" void* fn_114_ED00(void* object, short deleting) {
    if (object != 0) {
        fn_114_ECA0(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_114_ED60(void* object, short deleting) {
    if (object != 0) {
        fn_114_ED00(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
