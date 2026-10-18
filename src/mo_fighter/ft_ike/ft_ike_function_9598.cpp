#include <types.h>
#pragma force_active on

extern "C" void fn_27_D4B78(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_119_9598(void* receiver, s16 id, s32 argument) {
    fn_27_D4B78(receiver, id, receiver, static_cast<s8>(argument));
}
