#include <types.h>
#pragma force_active on

extern "C" void* fn_114_1DDC4(void* object, short deleting);
extern "C" void fn_114_5680(void*, short);
void operator delete(void* object);

extern "C" void* fn_114_1DD54(void* object, short deleting) {
    if (object != 0) {
        fn_114_5680(static_cast<char*>(object) + 0x14e0, -1);
        fn_114_1DDC4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
