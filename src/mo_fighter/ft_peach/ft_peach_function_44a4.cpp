#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* __dt__19soPostureModuleImplFv(void* member, s16 deleteFlag);
void* fn_27_19FFEC(void* member, s16 deleteFlag);

void* fn_103_44A4(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        __dt__19soPostureModuleImplFv(static_cast<u8*>(object) + 0x3C, memberDeleteFlag);
        if (object != nullptr) {
            fn_27_19FFEC(object, memberDeleteFlag);
        }
        if (deleteFlag > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
