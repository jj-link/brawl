#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_B4A8(void* member, s16 deleteFlag);

void* fn_103_B568(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        void* base = object;
        if (base != nullptr) {
            s16 memberDeleteFlag = -1;
            fn_103_B4A8(static_cast<u8*>(base) + 4, memberDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
