#include <sr/sr_common.h>
#include <types.h>

extern "C" {
void* fn_103_A60C(void* member, s16 deleteFlag);
void* fn_103_51C4(void* member, s16 deleteFlag);
void* fn_103_5234(void* member, s16 deleteFlag);

void* fn_103_541C(void* object, s32 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_A60C(static_cast<u8*>(object) + 0xE0, memberDeleteFlag);
        fn_103_51C4(static_cast<u8*>(object) + 0x30, memberDeleteFlag);
        fn_103_5234(object, memberDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
