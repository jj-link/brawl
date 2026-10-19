#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_103_1B00(void* object, s16 deleteFlag);

void* fn_103_1AA4(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = 0;
        fn_103_1B00(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
