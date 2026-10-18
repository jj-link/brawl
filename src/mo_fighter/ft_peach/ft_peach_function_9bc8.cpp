#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* __dt__21ftExtendParamAccesserFv(void* object, s16 deleteFlag);

void* fn_103_9BC8(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        void* base = object;
        if (base != nullptr) {
            s16 baseDeleteFlag = 0;
            __dt__21ftExtendParamAccesserFv(base, baseDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
