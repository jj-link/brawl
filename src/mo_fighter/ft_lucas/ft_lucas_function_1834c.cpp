#include <types.h>
#pragma force_active on

extern "C" void fn_114_57E0(void* object, short deleting);
extern "C" void* fn_114_1860C(char* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_1834C(void* object, short deleting) {
    if (object != 0) {
        fn_114_57E0(static_cast<char*>(object) + 0x9D9C, -1);
        fn_114_1860C(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
