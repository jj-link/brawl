#include <sr/sr_common.h>
#include <types.h>

extern "C" {
void* fn_27_1A1E70(void* member, s16 deleteFlag);
void* fn_103_5F44(void* base, s16 deleteFlag);

void* fn_103_5ED4(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_1A1E70(static_cast<u8*>(object) + 0x1C, memberDeleteFlag);
        s16 baseDeleteFlag = 0;
        fn_103_5F44(object, baseDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
