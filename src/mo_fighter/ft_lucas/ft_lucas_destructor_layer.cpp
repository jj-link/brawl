#include <types.h>

extern "C" void* fn_114_F224(void* object, short deleting);
extern "C" void* fn_114_F0EC(void* object, short deleting);
extern "C" void* fn_114_3A20(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_F284(void* object, short deleting) {
    if (object != 0) {
        fn_114_F224(static_cast<char*>(object) + 0x17c, -1);
        if (object != 0) {
            fn_114_F0EC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_114_F2FC(void* object, short deleting) {
    if (object != 0) {
        fn_114_3A20(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_114_F358(void* object, short deleting) {
    if (object != 0) {
        fn_114_F2FC(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_114_F3B8(void* object, short deleting) {
    if (object != 0) {
        fn_114_F358(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
