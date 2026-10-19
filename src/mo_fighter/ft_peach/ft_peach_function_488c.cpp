#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_4950(void* member, s16 deleteFlag);

void* fn_103_488C(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        void* member = object;
        if (object != nullptr) {
            s16 memberDeleteFlag = -1;
            fn_103_4950(static_cast<u8*>(member) + 4, memberDeleteFlag);
        }
        if (deleteFlag > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
