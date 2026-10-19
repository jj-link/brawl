#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_103_3944(void* member, s16 deleteFlag);
void* fn_103_39A0(void* member, s16 deleteFlag);
void* fn_103_39FC(void* member, s16 deleteFlag);
void* fn_103_2E30(void* member, s16 deleteFlag);
void* fn_103_3A58(void* member, s16 deleteFlag);
void* fn_103_3AE4(void* member, s16 deleteFlag);
void* fn_103_3BE0(void* member, s16 deleteFlag);
void* fn_103_3D1C(void* member, s16 deleteFlag);
void* fn_103_3F84(void* member, s16 deleteFlag);
void* fn_103_40B8(void* member, s16 deleteFlag);
void* fn_103_4114(void* member, s16 deleteFlag);
void* fn_103_4170(void* member, s16 deleteFlag);
void* fn_103_41DC(void* member, s16 deleteFlag);
void* fn_103_423C(void* member, s16 deleteFlag);
void* fn_103_429C(void* member, s16 deleteFlag);
void* fn_103_42F8(void* member, s16 deleteFlag);
void* fn_103_437C(void* member, s16 deleteFlag);
void* fn_103_4448(void* member, s16 deleteFlag);
void* fn_103_44A4(void* member, s16 deleteFlag);
void* fn_103_12CBC(void* member, s16 deleteFlag);
void* fn_103_45A0(void* member, s16 deleteFlag);
void* fn_103_460C(void* member, s16 deleteFlag);
void* fn_103_46C4(void* member, s16 deleteFlag);
void* fn_103_4704(void* member, s16 deleteFlag);
void* __dt__16soModuleAccesserFv(void* member, s16 deleteFlag);
void* fn_103_4760(void* object, s16 deleteFlag);

void* fn_103_12AD4(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        s16 memberDeleteFlag = -1;
        fn_103_3944(static_cast<u8*>(object) + 0x1978, memberDeleteFlag);
        fn_103_39A0(static_cast<u8*>(object) + 0x1960, memberDeleteFlag);
        fn_103_39FC(static_cast<u8*>(object) + 0x1808, memberDeleteFlag);
        fn_103_2E30(static_cast<u8*>(object) + 0x17BC, memberDeleteFlag);
        fn_103_3A58(static_cast<u8*>(object) + 0x1624, memberDeleteFlag);
        fn_103_3AE4(static_cast<u8*>(object) + 0x15C4, memberDeleteFlag);
        fn_103_3BE0(static_cast<u8*>(object) + 0x1510, memberDeleteFlag);
        fn_103_3D1C(static_cast<u8*>(object) + 0x1350, memberDeleteFlag);
        fn_103_3F84(static_cast<u8*>(object) + 0x12AC, memberDeleteFlag);
        fn_103_40B8(static_cast<u8*>(object) + 0x1278, memberDeleteFlag);
        fn_103_4114(static_cast<u8*>(object) + 0x1244, memberDeleteFlag);
        fn_103_4170(static_cast<u8*>(object) + 0x10E0, memberDeleteFlag);
        fn_103_41DC(static_cast<u8*>(object) + 0x1078, memberDeleteFlag);
        fn_103_423C(static_cast<u8*>(object) + 0x106C, memberDeleteFlag);
        fn_103_429C(static_cast<u8*>(object) + 0x1044, memberDeleteFlag);
        fn_103_42F8(static_cast<u8*>(object) + 0xE74, memberDeleteFlag);
        fn_103_437C(static_cast<u8*>(object) + 0xE10, memberDeleteFlag);
        fn_103_4448(static_cast<u8*>(object) + 0xDD4, memberDeleteFlag);
        fn_103_44A4(static_cast<u8*>(object) + 0xD1C, memberDeleteFlag);
        fn_103_12CBC(static_cast<u8*>(object) + 0xB10, memberDeleteFlag);
        fn_103_45A0(static_cast<u8*>(object) + 0x930, memberDeleteFlag);
        fn_103_460C(static_cast<u8*>(object) + 0x900, memberDeleteFlag);
        fn_103_46C4(static_cast<u8*>(object) + 0x8F0, memberDeleteFlag);
        fn_103_4704(static_cast<u8*>(object) + 0x8D8, memberDeleteFlag);
        __dt__16soModuleAccesserFv(static_cast<u8*>(object) + 0x7F8, memberDeleteFlag);
        fn_103_4760(object, memberDeleteFlag);
        if (deleteFlag > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
