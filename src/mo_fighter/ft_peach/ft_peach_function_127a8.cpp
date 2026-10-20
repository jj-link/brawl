#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_37B0(void* member, s16 deleteFlag);
void* fn_27_1DBB60(void* member, s16 deleteFlag);
void* fn_103_12830(void* member, s16 deleteFlag);
void* fn_27_1D81C8(void* self, s16 flag);

void* fn_103_127A8(void* object, s32 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_37B0(static_cast<u8*>(object) + 0x2070, memberDeleteFlag);
        fn_27_1DBB60(static_cast<u8*>(object) + 0x2038, memberDeleteFlag);
        fn_103_12830(static_cast<u8*>(object) + 0xCC, memberDeleteFlag);
        fn_27_1D81C8(object, static_cast<short>(0));
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
