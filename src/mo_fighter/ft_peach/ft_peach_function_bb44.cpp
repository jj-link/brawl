#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_103_BAE4(void* member, s16 deleteFlag);

void* fn_103_BB44(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        fn_103_BAE4(static_cast<u8*>(object) + 8, -1);
        if (deleteFlag > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
