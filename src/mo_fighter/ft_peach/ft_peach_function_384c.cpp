#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_2264(void* member, s16 deleteFlag);
void* fn_103_2188(void* member, s16 deleteFlag);

void* fn_103_384C(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_2264(static_cast<u8*>(object) + 0x50, memberDeleteFlag);
        fn_103_2188(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
