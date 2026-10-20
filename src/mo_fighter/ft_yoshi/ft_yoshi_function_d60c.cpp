#include <stddef.h>
#pragma force_active on

void operator delete(void*);
extern "C" void fn_95_D5AC(void* object, short deleting);
extern "C" void* fn_95_D47C(void* object, short deleting);

extern "C" void* fn_95_D60C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_95_D5AC(storage + 0x94, -1);
        if (object != 0) {
            fn_95_D47C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
