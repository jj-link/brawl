#include <types.h>
#pragma force_active on

extern "C" void fn_27_D4DF4(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_110_9508(void* receiver, s16 id, s8 argument) {
    fn_27_D4DF4(receiver, id, receiver, argument);
}
