#include <st/module.h>
#pragma force_active on

extern "C" void fn_119_B3C8(void* object, short deleting);
extern "C" void* fn_119_B294(void* object, short deleting);

void operator delete(void*);

extern "C" void* fn_119_B428(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_119_B3C8(storage + 0x1C8, -1);
        if (object != 0) {
            fn_119_B294(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
