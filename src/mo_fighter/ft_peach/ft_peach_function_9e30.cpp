#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A7B4C(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_103_9E30(void* receiver, s16 id, s8 argument) {
    fn_27_1A7B4C(receiver, id, receiver, argument);
}
