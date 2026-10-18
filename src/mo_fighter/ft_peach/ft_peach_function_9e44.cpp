#include <types.h>
#pragma force_active on

extern "C" void fn_27_D3C0C(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_103_9E44(void* receiver, s16 id, s8 argument) {
    fn_27_D3C0C(receiver, id, receiver, argument);
}
