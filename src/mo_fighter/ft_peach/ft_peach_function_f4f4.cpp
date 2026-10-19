#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_F644(void* object, s16 deleteFlag);

void* fn_103_F4F4(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = 0;
        fn_103_F644(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
