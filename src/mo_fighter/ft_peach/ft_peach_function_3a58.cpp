#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_97968(void* member, s16 deleteFlag);
void* fn_27_1CCCC(void* member, s16 deleteFlag);
void* fn_103_30E8(void* member, s16 deleteFlag);
void* fn_27_CBF58(void* member, s16 deleteFlag);

void* fn_103_3A58(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_27_97968(static_cast<u8*>(object) + 0x58, memberDeleteFlag);
        fn_27_1CCCC(static_cast<u8*>(object) + 0x48, memberDeleteFlag);
        fn_103_30E8(static_cast<u8*>(object) + 0x3C, memberDeleteFlag);
        if (object != nullptr) {
            fn_27_CBF58(object, memberDeleteFlag);
        }
        if (deleteFlag > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
