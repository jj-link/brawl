#include <types.h>
#pragma force_active on

extern "C" void fn_27_D443C(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_110_951C(void* receiver, s16 id, int argument) {
    fn_27_D443C(receiver, id, receiver, static_cast<s8>(argument));
}
