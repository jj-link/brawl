#include <types.h>
#pragma force_active on

extern "C" void fn_27_D5464(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_119_95DC(void* receiver, s16 id, s32 argument) {
    fn_27_D5464(receiver, id, receiver, (s8)argument);
}
