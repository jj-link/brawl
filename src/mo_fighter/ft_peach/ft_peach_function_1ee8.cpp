#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_7700(void* member, s16 value);

void* fn_103_1EE8(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberFlag = 0;
        fn_27_7700(object, memberFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
