#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_1A241C(void* member, s16 deleteFlag);
void* fn_103_3C7C(void* member, s16 deleteFlag);
void* fn_103_1F44(void* member, s16 deleteFlag);
void* fn_103_3CBC(void* object, s16 deleteFlag);

void* fn_103_3BE0(void* object, s16 deleteFlag) {
    if (object != nullptr) {
        u8* base = static_cast<u8*>(object);
        if (base + 0x30 != nullptr) {
            fn_27_1A241C(base + 0x40, -1);
            fn_103_3C7C(base + 0x30, 0);
        }
        if (object != nullptr) {
            fn_103_1F44(base + 0x20, 0);
            fn_103_3CBC(object, 0);
        }
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(object);
        }
    }
    return object;
}
}
