#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_384C(void* member, s16 deleteFlag);
void* fn_103_12930(void* member, s16 deleteFlag);
void* fn_103_129BC(void* member, s16 deleteFlag);
void* fn_103_12A48(void* member, s16 deleteFlag);
void* fn_103_38B8(void* member, s16 deleteFlag);

void* fn_103_128A0(void* object, s32 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_384C(static_cast<u8*>(object) + 0x4B0, memberDeleteFlag);
        fn_103_12930(static_cast<u8*>(object) + 0x384, memberDeleteFlag);
        fn_103_129BC(static_cast<u8*>(object) + 0x258, memberDeleteFlag);
        fn_103_12A48(static_cast<u8*>(object) + 0x12C, memberDeleteFlag);
        fn_103_38B8(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
