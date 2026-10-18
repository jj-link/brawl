#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" void* fn_103_F4B4(void* object, s32 deleteFlag) {
    if (object != nullptr && static_cast<s16>(deleteFlag) > 0) {
        ::operator delete(object);
    }
    return object;
}
