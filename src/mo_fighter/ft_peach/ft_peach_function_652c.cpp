#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_614C4(void* member, s16 deleteFlag);
void* fn_27_D3080(void* member, s16 deleteFlag);

void* fn_103_652C(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_614C4(static_cast<u8*>(object) + 0xAC, memberDeleteFlag);
        if (object != nullptr) {
            fn_27_D3080(object, memberDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
