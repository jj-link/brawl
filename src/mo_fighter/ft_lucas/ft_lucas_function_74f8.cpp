#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A15B8(void* object, short value);
extern "C" void* fn_114_7570(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_74F8(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<char*>(object) + 0x1fc, -1);
        if (object != 0) {
            fn_114_7570(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
