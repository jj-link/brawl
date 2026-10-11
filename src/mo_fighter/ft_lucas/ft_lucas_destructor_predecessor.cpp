#include <types.h>

extern "C" void* fn_114_EEF8(void* object, short deleting);
extern "C" void* fn_114_EDC0(void* object, short deleting);
extern "C" void* fn_114_EE38(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_EF58(void* object, short deleting) {
    if (object != 0) {
        fn_114_EEF8(static_cast<char*>(object) + 0xec, -1);
        if (object != 0) {
            fn_114_EDC0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_114_EFD0(void* object, short deleting) {
    if (object != 0) {
        fn_114_EE38(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_114_F02C(void* object, short deleting) {
    if (object != 0) {
        fn_114_EFD0(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_114_F08C(void* object, short deleting) {
    if (object != 0) {
        fn_114_F02C(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
