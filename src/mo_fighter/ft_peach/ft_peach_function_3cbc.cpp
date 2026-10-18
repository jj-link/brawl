#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_103_1EE8(void* member, s16 deleteFlag);

void* fn_103_3CBC(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        fn_103_1EE8(static_cast<u8*>(object) + 0x8, 0);
        if (deleteFlag > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
