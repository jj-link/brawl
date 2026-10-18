#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_103_BA88(void* member, s16 deleteFlag);

void* fn_103_BAE4(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        fn_103_BA88(static_cast<u8*>(object) + 4, -1);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
