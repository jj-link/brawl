#include <stddef.h>
#pragma force_active on

extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void* fn_107_6CF4(void*, short);
extern "C" void operator delete(void*);

extern "C" void* fn_107_6C7C(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70((char*)object + 0x4B8, -1);
        if (object != 0) {
            fn_107_6CF4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
