#include <types.h>
#pragma force_active on

extern "C" void fn_27_D46B8(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_112_A5E4(void* receiver, s16 id, s8 argument) {
    fn_27_D46B8(receiver, id, receiver, argument);
}
