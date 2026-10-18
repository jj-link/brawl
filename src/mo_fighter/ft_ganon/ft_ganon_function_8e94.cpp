#include <types.h>
#pragma force_active on

extern "C" void fn_27_D4DF4(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_109_8E94(void* receiver, s16 id, int argument) {
    fn_27_D4DF4(receiver, static_cast<s16>(id), receiver, static_cast<s8>(argument));
}
