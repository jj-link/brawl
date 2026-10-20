#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void* fn_114_7138(void*, short);
void operator delete(void* object);

extern "C" void* fn_114_70C0(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<char*>(object) + 0x4b8, -1);
        if (object != 0) {
            fn_114_7138(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
