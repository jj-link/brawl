#include <sr/sr_common.h>
#include <types.h>

extern "C" {
void* fn_103_3EE4(void* member, s16 deleteFlag);
void* fn_103_5604(void* member, s16 deleteFlag);
void* fn_27_19E99C(void* member, s16 deleteFlag);

void* fn_103_558C(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_3EE4(static_cast<u8*>(object) + 0x87C, memberDeleteFlag);
        fn_103_5604(static_cast<u8*>(object) + 0x19C, memberDeleteFlag);
        fn_27_19E99C(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
