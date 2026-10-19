#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void __dt__19soPostureModuleImplFv(void* member, s16 deleteFlag);
void fn_27_1A0184(void* member, s16 deleteFlag);

void* fn_103_6A4C(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        __dt__19soPostureModuleImplFv(static_cast<u8*>(object) + 0x6C, memberDeleteFlag);
        if (object != nullptr) {
            fn_27_1A0184(object, memberDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
