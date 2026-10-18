#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A76C4(void* receiver, s32 id, void* owner, s8 argument);

extern "C" void fn_118_A15C(void* receiver, s16 id, s32 argument) {
    fn_27_1A76C4(receiver, static_cast<s32>(id), receiver, static_cast<s8>(argument));
}
