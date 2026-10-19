#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* __dt__16acCmdInterpreterFv(void* object, s16 deleteFlag);

void* fn_103_2188(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        __dt__16acCmdInterpreterFv(object, 0);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
