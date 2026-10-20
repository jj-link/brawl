#include <types.h>
#include <sr/sr_common.h>
#pragma force_active on

extern "C" {
void* fn_27_C74E8(void* member, s16 deleteFlag);
void* fn_103_7170(void* object, s16 deleteFlag);
void* fn_103_194C(void* object, s16 deleteFlag);

void* fn_103_9C84(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        fn_27_C74E8(static_cast<u8*>(object) + 0x186FC, -1);
        s16 flag = 0;
        fn_103_7170(static_cast<u8*>(object) + 0x186F0, flag);
        fn_103_194C(object, flag);
        if (deleteFlag > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
