#include <sr/sr_common.h>
#include <types.h>

extern "C" {
void* fn_103_3E00(void* member, s16 deleteFlag);
void* fn_103_3E84(void* member, s16 deleteFlag);
void* fn_103_5530(void* member, s16 deleteFlag);
void* fn_103_558C(void* member, s16 deleteFlag);
void* fn_103_5FA4(void* member, s16 deleteFlag);
void* fn_27_C74E8(void* member, s16 deleteFlag);

void* fn_103_5494(void* object, s32 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_3E00(static_cast<u8*>(object) + 0xDEC, memberDeleteFlag);
        fn_103_3E84(static_cast<u8*>(object) + 0xDD8, memberDeleteFlag);
        fn_103_5530(static_cast<u8*>(object) + 0x950, memberDeleteFlag);
        fn_103_558C(static_cast<u8*>(object) + 0xBC, memberDeleteFlag);
        fn_103_5FA4(static_cast<u8*>(object) + 0x10, memberDeleteFlag);
        fn_27_C74E8(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
