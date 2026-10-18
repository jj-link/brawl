#include <types.h>
#pragma force_active on

extern "C" void fn_27_D5464(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_98_9CA0(void* receiver, s16 id, s8 priority) {
    fn_27_D5464(receiver, id, receiver, priority);
}
