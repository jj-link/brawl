#include <types.h>
#pragma force_active on

extern "C" void* fn_27_6A3D8(void* object, s16 value);
extern "C" void* fn_27_199BBC(void* object, s16 count);

extern "C" void* fn_111_5068(void* object, s16 flag) {
    if (object != 0) {
        fn_27_6A3D8(static_cast<u8*>(object) + 0x27C, -1);
        fn_27_199BBC(object, -1);
        if (flag > 0) {
            operator delete(object);
        }
    }
    return object;
}
