#include <types.h>
#pragma force_active on

extern "C" void fn_27_D3E88(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_115_9EE4(void* receiver, s16 id, s8 argument) {
    fn_27_D3E88(receiver, id, receiver, argument);
}
