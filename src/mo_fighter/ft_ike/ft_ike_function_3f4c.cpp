#include <stddef.h>
#pragma force_active on

extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void fn_119_3FC4(void* object, short deleting);
void operator delete(void*);

extern "C" void* fn_119_3F4C(void* object, short deleting) {
    unsigned char* storage = static_cast<unsigned char*>(object);
    if (object != 0) {
        fn_27_1A1B88(storage + 0x218, -1);
        if (object != 0) {
            fn_119_3FC4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
