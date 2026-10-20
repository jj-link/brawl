#include <types.h>
#pragma force_active on

extern "C" void* fn_27_D2904(void* member, s16 deleteFlag);
extern "C" void fn_111_4C38(void* object, s16 flag);

extern "C" void* fn_111_4BC0(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<u8*>(object) + 0xB4, -1);
        if (object != 0) {
            fn_111_4C38(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
