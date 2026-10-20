#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void* fn_27_82AD4(void*, short);
void* fn_27_4CAA0(void*, short);
void* fn_27_19CA80(void*, short);
void __dl__FPv(void*);

void* fn_103_42F8(void* object, s32 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        __dt__27soCollisionAttackModuleImplFv(static_cast<u8*>(object) + 0x124, memberDeleteFlag);
        fn_27_82AD4(static_cast<u8*>(object) + 0x120, memberDeleteFlag);
        fn_27_4CAA0(static_cast<u8*>(object) + 0x9c, memberDeleteFlag);
        fn_27_19CA80(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
