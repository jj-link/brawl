#include <types.h>
#pragma force_active on

extern "C" void fn_27_D5464(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_117_A330(void* receiver, s16 id, s8 argument) {
    fn_27_D5464(receiver, id, receiver, argument);
}