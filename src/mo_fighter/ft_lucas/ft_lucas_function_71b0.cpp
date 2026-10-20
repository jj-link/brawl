#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void* fn_114_7228(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_71B0(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8(static_cast<char*>(object) + 0x470, -1);
        if (object != 0) {
            fn_114_7228(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
