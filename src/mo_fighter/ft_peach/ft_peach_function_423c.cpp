#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_6880C(void* member, s16 deleteFlag);

void* fn_103_423C(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        fn_27_6880C(static_cast<u8*>(object) + 4, -1);
        if (deleteFlag > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
