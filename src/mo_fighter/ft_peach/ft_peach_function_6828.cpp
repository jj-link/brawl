#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* __dt__27soCollisionAttackModuleImplFv(void*, s16);
void* fn_27_1A12AC(void*, s16);
void* fn_27_CB998(void*, s16);
void fn_27_19D158(void*, s16);

void* fn_103_6828(void* object, s32 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        __dt__27soCollisionAttackModuleImplFv(static_cast<u8*>(object) + 0x73C, memberDeleteFlag);
        fn_27_1A12AC(static_cast<u8*>(object) + 0x660, memberDeleteFlag);
        fn_27_CB998(static_cast<u8*>(object) + 0x3FC, memberDeleteFlag);
        fn_27_19D158(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
