#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_1F44(void* member, s16 deleteFlag);
void* fn_103_3CBC(void* member, s16 deleteFlag);

void* fn_103_5234(void* member, s16 deleteFlag) {
    if (member != nullptr) {
        s16 memberDeleteFlag = 0;
        fn_103_1F44(static_cast<u8*>(member) + 0x20, memberDeleteFlag);
        fn_103_3CBC(member, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(member);
        }
    }
    return member;
}
}
