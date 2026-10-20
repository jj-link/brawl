#include <types.h>
#pragma force_active on

extern "C" void* fn_114_3AA0(void* object, short deleting);
extern "C" void* fn_27_1DBB60(void* object, short deleting);
extern "C" void* fn_114_20020(void* object, short deleting);
extern "C" void* fn_27_1D81C8(void* object, short deleting);
void operator delete(void* object);

extern "C" void* fn_114_1FF98(void* object, short deleting) {
    if (object != 0) {
        fn_114_3AA0(static_cast<char*>(object) + 0x2088, -1);
        fn_27_1DBB60(static_cast<char*>(object) + 0x2050, -1);
        fn_114_20020(static_cast<char*>(object) + 0xCC, -1);
        fn_27_1D81C8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
