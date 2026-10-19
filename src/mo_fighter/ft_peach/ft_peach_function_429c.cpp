#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* __dt__16soStopModuleImplFv(void* object, s16 deleteFlag);

void* fn_103_429C(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        __dt__16soStopModuleImplFv(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
