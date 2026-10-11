#include <types.h>

extern "C" void* fn_114_F490(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_F4EC(void* object, short deleting) {
    if (object != 0) {
        fn_114_F490(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_114_F54C(void* object, short deleting) {
    if (object != 0) {
        fn_114_F4EC(static_cast<char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
