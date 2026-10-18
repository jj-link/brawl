#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A8014(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_108_AE58(void* receiver, s16 id, s32 unit, s32 argument) {
    fn_27_1A8014(receiver, id, receiver, static_cast<s8>(unit));
}
