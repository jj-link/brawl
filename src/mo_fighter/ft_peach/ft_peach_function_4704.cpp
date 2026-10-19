#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* __dt__16soHeapModuleImplFv(void* member, s16 deleteFlag);

void* fn_103_4704(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        __dt__16soHeapModuleImplFv(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
