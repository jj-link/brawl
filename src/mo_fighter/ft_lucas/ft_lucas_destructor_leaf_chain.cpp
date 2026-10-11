#include <types.h>

extern "C" void* fn_114_3A20(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_E930(void* object, short deleting) {
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

extern "C" void* fn_114_E990(void* object, short deleting) {
    if (object != 0) {
        fn_114_E930(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_114_E9F0(void* object, short deleting) {
    if (object != 0) {
        fn_114_E990(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_114_EA50(void* object, short deleting) {
    if (object != 0) {
        fn_114_E9F0(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
