#include <sr/sr_common.h>
#include <types.h>

extern "C" {
void* fn_27_1A383C(void* member, s16 deleteFlag);

void* fn_103_5530(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_1A383C(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
