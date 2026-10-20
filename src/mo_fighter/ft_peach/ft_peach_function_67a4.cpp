#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void __dt__24soCollisionHitModuleImplFv(void*, s16);
void* fn_27_CC984(void*, s16);
void* fn_27_4CAA0(void*, s16);
void* fn_27_19B704(void*, s16);

void* fn_103_67A4(void* object, s32 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        __dt__24soCollisionHitModuleImplFv(static_cast<u8*>(object) + 0x8f4, memberDeleteFlag);
        fn_27_CC984(static_cast<u8*>(object) + 0x8b0, memberDeleteFlag);
        fn_27_4CAA0(static_cast<u8*>(object) + 0x82c, memberDeleteFlag);
        fn_27_19B704(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
