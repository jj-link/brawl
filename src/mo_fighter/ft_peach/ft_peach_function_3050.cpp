#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_97968(void* member, s16 deleteFlag);
void* fn_27_1CCCC(void* member, s16 deleteFlag);
void* fn_103_30E8(void* member, s16 deleteFlag);
void* fn_103_3144(void* member, s16 deleteFlag);
void* fn_27_CBF58(void* member, s16 deleteFlag);

void* fn_103_3050(void* object, s32 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_97968(static_cast<u8*>(object) + 0x6C, memberDeleteFlag);
        fn_27_1CCCC(static_cast<u8*>(object) + 0x5C, memberDeleteFlag);
        fn_103_30E8(static_cast<u8*>(object) + 0x50, memberDeleteFlag);
        fn_103_3144(static_cast<u8*>(object) + 0x38, memberDeleteFlag);
        if (object != nullptr) {
            fn_27_CBF58(object, memberDeleteFlag);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
