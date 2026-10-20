#include <stddef.h>
#pragma force_active on

extern "C" void fn_105_FEB8(void* object, short deleting);
extern "C" void fn_105_FD80(void* object, short deleting);
void operator delete(void*);

extern "C" void* fn_105_FF18(void* object, short deleting) {
    if (object != 0) {
        fn_105_FEB8(static_cast<unsigned char*>(object) + 0x17C, -1);
        if (object != 0) {
            fn_105_FD80(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
