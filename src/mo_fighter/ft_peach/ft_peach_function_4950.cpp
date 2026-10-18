#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_49B0(void* member, s16 deleteFlag);

void* fn_103_4950(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_49B0(static_cast<u8*>(object) + 8, memberDeleteFlag);
        if (deleteFlag > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
