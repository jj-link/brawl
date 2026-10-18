#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A8258(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_105_D940(void* receiver, s16 id, int argument) {
    fn_27_1A8258(receiver, static_cast<s16>(id), receiver, static_cast<s8>(argument));
}
