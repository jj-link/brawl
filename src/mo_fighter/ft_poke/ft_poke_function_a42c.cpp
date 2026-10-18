#include <types.h>
#pragma force_active on

extern "C" void fn_27_D46B8(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_116_A42C(void* receiver, s16 id, int argument) {
    fn_27_D46B8(receiver, static_cast<s16>(id), receiver, static_cast<s8>(argument));
}
