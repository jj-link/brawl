#include <types.h>
#pragma force_active on

extern "C" void fn_27_D512C(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_105_D968(void* receiver, s16 id, int argument) {
    fn_27_D512C(receiver, id, receiver, static_cast<s8>(argument));
}
