#include <types.h>

extern "C" void* fn_114_ED60(void* object, short deleting);
extern "C" void* fn_114_EC30(void* object, short deleting);
extern "C" void* fn_114_3A20(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_EDC0(void* object, short deleting) {
    if (object != 0) {
        fn_114_ED60(static_cast<char*>(object) + 0x94, -1);
        if (object != 0) {
            fn_114_EC30(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_114_EE38(void* object, short deleting) {
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

extern "C" void* fn_114_EE98(void* object, short deleting) {
    if (object != 0) {
        fn_114_EE38(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_114_EEF8(void* object, short deleting) {
    if (object != 0) {
        fn_114_EE98(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
