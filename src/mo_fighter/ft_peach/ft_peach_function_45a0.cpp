#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* __dt__17soModelModuleImplFv(void* member, s16 deleteFlag);
void* fn_27_CBDE8(void* member, s16 deleteFlag);

void* fn_103_45A0(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        __dt__17soModelModuleImplFv(static_cast<u8*>(object) + 0x114, memberDeleteFlag);
        fn_27_CBDE8(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
