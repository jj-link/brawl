#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_3B44(void* member, s16 deleteFlag);

void* fn_103_3AE4(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        fn_103_3B44(static_cast<u8*>(object) + 0x38, -1);
        if (deleteFlag > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
