#include <types.h>
#pragma force_active on

extern "C" void* fn_27_93100(void*, short);
extern "C" void* fn_114_33CC(void*, short);
extern "C" void* fn_27_19F4C4(void*, short);
extern "C" void* fn_27_1A55B0(void*, short);
void operator delete(void* object);

extern "C" void* fn_114_3344(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_27_93100(storage + 0x407D8, destroy);
        fn_114_33CC(storage + 0x7C, destroy);
        fn_27_19F4C4(storage + 0x20, destroy);
        fn_27_1A55B0(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
