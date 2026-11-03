#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_20FC(void* member, s16 deleteFlag);
void* fn_103_22C0(void* member, s16 deleteFlag);
void* fn_103_2388(void* member, s16 deleteFlag);
void* fn_103_2414(void* member, s16 deleteFlag);
void* fn_103_24A0(void* member, s16 deleteFlag);
void* fn_103_252C(void* member, s16 deleteFlag);
void* fn_103_25B8(void* member, s16 deleteFlag);
void* fn_103_2644(void* member, s16 deleteFlag);
void* fn_103_26D0(void* member, s16 deleteFlag);
void* fn_103_275C(void* member, s16 deleteFlag);
void* fn_103_27E8(void* object, s16 deleteFlag);

void* fn_103_2024(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_20FC(static_cast<u8*>(object) + 0x14B0, memberDeleteFlag);
        fn_103_22C0(static_cast<u8*>(object) + 0x138C, memberDeleteFlag);
        fn_103_2388(static_cast<u8*>(object) + 0x1260, memberDeleteFlag);
        fn_103_2414(static_cast<u8*>(object) + 0x1134, memberDeleteFlag);
        fn_103_24A0(static_cast<u8*>(object) + 0x1008, memberDeleteFlag);
        fn_103_252C(static_cast<u8*>(object) + 0xEDC, memberDeleteFlag);
        fn_103_25B8(static_cast<u8*>(object) + 0xDB0, memberDeleteFlag);
        fn_103_2644(static_cast<u8*>(object) + 0xC84, memberDeleteFlag);
        fn_103_26D0(static_cast<u8*>(object) + 0xB58, memberDeleteFlag);
        fn_103_275C(static_cast<u8*>(object) + 0xA2C, memberDeleteFlag);
        fn_103_27E8(object, memberDeleteFlag);
        if (deleteFlag > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
