#include <types.h>

extern "C" void* fn_114_F3B8(void* object, short deleting);
extern "C" void* fn_114_F284(void* object, short deleting);
extern "C" void* fn_114_3A20(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_F418(void* object, short deleting) {
    if (object != 0) {
        fn_114_F3B8(static_cast<char*>(object) + 0x1c8, -1);
        if (object != 0) {
            fn_114_F284(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}

extern "C" void* fn_114_F490(void* object, short deleting) {
    if (object != 0) {
        fn_114_3A20(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
