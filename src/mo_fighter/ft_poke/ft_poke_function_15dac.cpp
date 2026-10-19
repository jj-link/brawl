#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_1A5FD8(void* member, s16 deleteFlag);

void* fn_116_15DAC(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_1A5FD8(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
