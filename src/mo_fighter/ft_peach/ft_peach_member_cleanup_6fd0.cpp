#include <sr/sr_common.h>
#include <types.h>

extern "C" {
void* fn_27_14B698(void* member, s16 deleteFlag);

void* fn_103_6FD0(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_14B698(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
